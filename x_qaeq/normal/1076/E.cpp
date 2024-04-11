//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct edge{int to,nxt;}e[600005];int et,head[300005],n,m;
ll T[300005],rs[300005];vector<pair<int,int> >q[300005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void add(int x,int w) {for(;x<=n;x+=x&(-x)) T[x]+=w;}
inline ll qry(int x) {ll r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline void dfs(int x,int fa,int de)
{
	for(auto w:q[x]) add(de,w.second),add(de+w.first+1,-w.second);
	rs[x]=qry(de);for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x,de+1);
	for(auto w:q[x]) add(de,-w.second),add(de+w.first+1,w.second);
}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	read(m);for(int i=1,x,v,d;i<=m;i++) read(x),read(d),read(v),q[x].push_back(make_pair(d,v));
	dfs(1,0,1);for(int i=1;i<=n;i++) printf("%lld%c",rs[i],i==n?'\n':' ');
	return 0;
}