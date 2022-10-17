//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
//#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=200005;
int n,m,a[N],id[N],rt[N],ind,sz[N*80],lc[N*80],rc[N*80];
bool cmp(const int&x,const int&y){return a[x]>a[y]||(a[x]==a[y]&&x<y);}
void ins(int&u,int v,int l,int r,int x){
	u=++ind;
	sz[u]=sz[v]+1;
	lc[u]=lc[v],rc[u]=rc[v];
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)ins(lc[u],lc[v],l,mid,x);
	else ins(rc[u],rc[v],mid+1,r,x);
}
int query(int u,int l,int r,int x){
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(x<=sz[lc[u]])return query(lc[u],l,mid,x);
	else return query(rc[u],mid+1,r,x-sz[lc[u]]);
}
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]),id[i]=i;
	std::sort(id+1,id+1+n,cmp);
	rep(i,1,n)ins(rt[i],rt[i-1],1,n,id[i]);
	rd(m);
	rep(i,1,m){
		int k,pos;rd(k),rd(pos);
		pt(a[query(rt[k],1,n,pos)],'\n');
	}
	return 0;
}