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
const int MAXN=2e5;
int n,m,a[MAXN+5];vector<int> qv[MAXN+5];
struct event{int l,r,w;} b[MAXN+5];
struct node{int l,r;ll mx,lz;} s[MAXN*4+5];
void pushup(int k){s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void pushdown(int k){
	if(s[k].lz){
		s[k<<1].mx+=s[k].lz;s[k<<1].lz+=s[k].lz;
		s[k<<1|1].mx+=s[k].lz;s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
void modify(int k,int l,int r,ll x){
	if(l<=s[k].l&&s[k].r<=r){s[k].mx+=x;s[k].lz+=x;return;}
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
int main(){
	scanf("%d%d",&n,&m);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].w),qv[b[i].r].pb(i);
	build(1,0,n);
	for(int i=1;i<=n;i++){
		modify(1,i,i,s[1].mx);modify(1,0,i-1,-a[i]);
		for(int j=0;j<qv[i].size();j++){
			int id=qv[i][j];
			modify(1,0,b[id].l-1,b[id].w);
		}
	}
	printf("%lld\n",s[1].mx);
	return 0;
}