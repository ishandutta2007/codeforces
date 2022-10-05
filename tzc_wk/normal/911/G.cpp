#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int MAXV=100;
int n,qu,a[MAXN+5];
struct node{int l,r,tag[MAXV+5];} s[MAXN*4+5];
void init(int x){for(int i=1;i<=MAXV;i++) s[x].tag[i]=i;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;init(k);if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void pushdown(int k){
	for(int i=1;i<=MAXV;i++){
		s[k<<1].tag[i]=s[k].tag[s[k<<1].tag[i]];
		s[k<<1|1].tag[i]=s[k].tag[s[k<<1|1].tag[i]];
	}
	for(int i=1;i<=MAXV;i++) s[k].tag[i]=i;
}
void modify(int k,int l,int r,int a,int b){
	if(l<=s[k].l&&s[k].r<=r){
		for(int i=1;i<=MAXV;i++) if(s[k].tag[i]==a)
			s[k].tag[i]=b;
		return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,a,b);
	else if(l>mid) modify(k<<1|1,l,r,a,b);
	else modify(k<<1,l,mid,a,b),modify(k<<1|1,mid+1,r,a,b);
}
int get(int k,int p){
	if(s[k].l==s[k].r) return s[k].tag[a[p]];
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	return (p<=mid)?get(k<<1,p):get(k<<1|1,p);
}
int main(){
	scanf("%d",&n);build(1,1,n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&qu);
	while(qu--){
		int l,r,a,b;scanf("%d%d%d%d",&l,&r,&a,&b);
		modify(1,l,r,a,b);
	} for(int i=1;i<=n;i++) printf("%d%c",get(1,i)," \n"[i==n]);
	return 0;
}