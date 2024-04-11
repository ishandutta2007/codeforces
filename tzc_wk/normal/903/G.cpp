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
int n,m,qu,a[MAXN+5],b[MAXN+5];
vector<pii> qv[MAXN+5];
struct node{int l,r;ll mn,lz;} s[MAXN*4+5];
void pushup(int k){s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);}
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
void modify(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){
		s[k].mn+=x;s[k].lz+=x;return;
	} pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
ll mn[MAXN+5];
int main(){
	scanf("%d%d%d",&n,&m,&qu);
	for(int i=1;i<n;i++) scanf("%d%d",&a[i],&b[i+1]);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),qv[u].pb(mp(v,w));
	build(1,1,n);for(int i=1;i<=n;i++) modify(1,i,i,b[i]);
	for(int i=1;i<=n;i++){
		for(pii p:qv[i]) modify(1,1,p.fi,p.se);
		mn[i]=s[1].mn;//printf("%d %lld\n",i,mn[i]);
	} multiset<ll> st;
	for(int i=1;i<=n;i++) st.insert(a[i]+mn[i]);
	printf("%lld\n",*st.begin());
	while(qu--){
		int x,y;scanf("%d%d",&x,&y);
		st.erase(st.find(a[x]+mn[x]));a[x]=y;
		st.insert(a[x]+mn[x]);printf("%lld\n",*st.begin());
	}
	return 0;
}