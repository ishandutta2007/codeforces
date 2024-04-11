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
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
const int MAXV=1e6;
int n,qu,a[MAXN+5];
struct node{int l,r,mn,mnc,lz;} s[MAXV*4+5];
void pushup(int k){
	s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);s[k].mnc=0;
	if(s[k].mn==s[k<<1].mn) s[k].mnc+=s[k<<1].mnc;
	if(s[k].mn==s[k<<1|1].mn) s[k].mnc+=s[k<<1|1].mnc;
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void pushdown(int k){
	if(s[k].lz){
		s[k<<1].mn+=s[k].lz;s[k<<1].lz+=s[k].lz;
		s[k<<1|1].mn+=s[k].lz;s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
void modify_mnc(int k,int p,int x){
	if(s[k].l==s[k].r){s[k].mnc+=x;return;}
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(p<=mid) modify_mnc(k<<1,p,x);
	else modify_mnc(k<<1|1,p,x);
	pushup(k);
}
void modify(int k,int l,int r,int x){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r){s[k].lz+=x;s[k].mn+=x;return;}
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
void update(int x,int v){modify(1,min(a[x],a[x+1]),max(a[x],a[x+1])-1,v);}
int main(){
	scanf("%d%d",&n,&qu);multiset<int> st;a[0]=MAXV+1;a[n+1]=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),st.insert(a[i]);build(1,0,MAXV);
	for(int i=1;i<=n;i++) modify_mnc(1,a[i],1);
	for(int i=0;i<=n;i++) update(i,1);
	while(qu--){
		int x,v;scanf("%d%d",&x,&v);st.erase(st.find(a[x]));
		update(x-1,-1);update(x,-1);modify_mnc(1,a[x],-1);
		a[x]=v;st.insert(v);
		update(x-1,1);update(x,1);modify_mnc(1,a[x],1);
		printf("%d\n",s[1].mnc);
	}
	return 0;
}