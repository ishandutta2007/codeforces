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
const int N=800005;int n,Q,tt=0,fa[N];char c[N];ll T[N];
struct node{int ch[26],f;int& operator[](char c) {return ch[c-'a'];}}t[N];
struct edge{int to,nxt;}e[N];int et,head[N],dfn[N],sz[N],dt,pos[N];
struct quer{int ps,id,fg;};vector<quer>v[N];ll rs[N];
inline void add(int x) {for(;x<=tt+1;x+=x&(-x)) T[x]++;}
inline ll qry(int x) {ll r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x) {dfn[x]=++dt,sz[x]=1;for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to),sz[x]+=sz[e[i].to];}
inline void getfail()
{
	queue<int>q;for(char i='a';i<='z';i++) if(t[0][i]) t[t[0][i]].f=0,q.push(t[0][i]);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(char i='a';i<='z';i++)
			if(t[x][i]) t[t[x][i]].f=t[t[x].f][i],q.push(t[x][i]);
			else t[x][i]=t[t[x].f][i];
	}
	{for(int i=1;i<=tt;i++) adde(t[i].f,i);}dfs(0);
}
int main()
{
	read(n),read(Q);for(int i=1,m;i<=n;i++)
	{
		scanf("%s",c+1),m=strlen(c+1);int x=0;
		for(int j=1;j<=m;x=t[x][c[j++]]) if(!t[x][c[j]]) fa[t[x][c[j]]=++tt]=x;
		pos[i]=x;
	}
	getfail();for(int i=1,l,r,w;i<=Q;i++) read(l),read(r),read(w),
		v[l-1].push_back((quer){w,i,-1}),v[r].push_back((quer){w,i,1});
	for(int i=1;i<=n;i++)
	{
		for(int j=pos[i];j;j=fa[j]) add(dfn[j]);
		for(auto q:v[i]) {int x=pos[q.ps];rs[q.id]+=q.fg*(qry(dfn[x]+sz[x]-1)-qry(dfn[x]-1));}
	}
	for(int i=1;i<=Q;i++) printf("%lld\n",rs[i]);
	return 0;
}