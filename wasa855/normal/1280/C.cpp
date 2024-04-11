#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 300005
struct Edge
{
	int v,nxt,w;
};
Edge edge[N*2];
int fir[N],ss,n;
void add(int u,int v,int w)
{
	ss++;
	edge[ss].v=v,edge[ss].w=w,edge[ss].nxt=fir[u];
	fir[u]=ss;
	ss++;
	edge[ss].v=u,edge[ss].w=w,edge[ss].nxt=fir[v];
	fir[v]=ss;
}
int maxn,minn;
int siz[N];
void dfs(int u,int fa,int w)
{
	siz[u]=1;
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(v==fa) continue;
		dfs(v,u,edge[i].w);
		siz[u]+=siz[v];
	}
	if(u==1) return ;
	int minp=siz[u];
	if(n*2-siz[u]<minp) minp=n*2-siz[u];
	if(minp&1) minn+=w;
	maxn+=w*minp;
}
void work()
{
	n=read();
	for(int i=1;i<=2*n;i++) fir[i]=0;
	minn=maxn=ss=0;
	for(int i=1;i<2*n;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	dfs(1,0,0);
	printf("%lld %lld\n",minn,maxn);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}