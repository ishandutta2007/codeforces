#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 600005
struct Edge
{
	int v,nxt;
};
Edge edge[N];
int fir[N];
int ss=1;
int n,m;
int dgr[N];
bool vis[N];
int cnt=0;
void add(int u,int v)
{
	ss++;
	edge[ss].v=v;
	edge[ss].nxt=fir[u];
	fir[u]=ss;
	ss++;
	edge[ss].v=u;
	edge[ss].nxt=fir[v];
	fir[v]=ss;
}
void dfs(int u)
{
	for(int &i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(vis[i]) continue;
		vis[i]=vis[i^1]=1;
		dfs(v);
		if(cnt&1) printf("%d %d\n",u,v);
		else printf("%d %d\n",v,u);
		cnt++;
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		dgr[u]++,dgr[v]++;
		add(u,v);
	}
	int las=0;
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]&1)
		{
			if(las!=0)
			{
				add(las,i);
				dgr[las]++,dgr[i]++;
				m++;
				las=0;
			}
			else las=i;
		}
	}
	if(m&1) add(1,1),m++;
	cout<<m<<endl;
	dfs(1);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}