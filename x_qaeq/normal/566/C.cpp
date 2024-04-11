//{{{
#include<bits/stdc++.h>
 #define double long double
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=200005;struct edge{int to,w,nxt;}e[N<<1];int et,head[N];
int n,m,sz[N],mnd,rt,rs,a[N];char v[N];double ds[N],sm,mn=1e25,ss;
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void init(int x,int fa)
{
	sz[x]=1;for(int i=head[x];i;i=e[i].nxt)
		if(!v[e[i].to]&&e[i].to!=fa) init(e[i].to,x),sz[x]+=sz[e[i].to];
}
inline void getrt(int x,int fa,int tot)
{
	int mx=tot-sz[x];for(int i=head[x];i;i=e[i].nxt)
		if(!v[e[i].to]&&e[i].to!=fa) mx=max(mx,sz[e[i].to]),getrt(e[i].to,x,tot);
	if(mx<=mnd) mnd=mx,rt=x;
}
inline void dfs(int x,int fa,int rt,ll ls)
{
	ds[rt]+=pow(ls,0.5)*1.5*a[x],sm+=pow(ls,1.5)*a[x];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to^fa) dfs(e[i].to,x,rt,ls+e[i].w);
}
inline void solve(int x)
{
	if(v[x]) return;else v[x]=1,init(x,0),sm=ss=0;
	for(int i=head[x];i;i=e[i].nxt) ds[e[i].to]=0,dfs(e[i].to,x,e[i].to,e[i].w),ss+=ds[e[i].to];
	{if(sm<=mn) mn=sm,rs=x;} for(int i=head[x];i;i=e[i].nxt)
		if(ss<ds[e[i].to]*2) return mnd=114514,getrt(e[i].to,x,sz[e[i].to]),solve(rt);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y,w;i<n;i++) read(x),read(y),read(w),adde(x,y,w),adde(y,x,w);
	return mnd=114514,init(1,0),getrt(1,0,n),solve(rt),printf("%d %.10Lf\n",rs,mn),0;
}