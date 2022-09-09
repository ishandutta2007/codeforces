#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
vector<int> E[N];
bool was[N];
vector<int> wn[N];
vector<pair<int,int>> we[N];
void AddEdge(int u, int v){ E[u].pb(v);E[v].pb(u);}
int ans=0,a[N];
int DFS(int u, int p)
{
	was[u]=1;
	int Best=0;
	for(int v:E[u]) if(v!=p)
	{
		int tmp=DFS(v,u)+1;
		ans=max(ans,tmp+Best);
		Best=max(tmp,Best);
	}
	E[u].clear();
	return Best;
}
int main()
{
	int n,u,v;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		int x=a[i];
		for(int j=2;j*j<=x;j++)
		{
			if(x%j) continue;
			wn[j].pb(i);
			while(x%j==0) x/=j;
		}
		if(x>1) wn[x].pb(i);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		int x=__gcd(a[u],a[v]);
		for(int j=2;j*j<=x;j++)
		{
			if(x%j) continue;
			we[j].pb(mp(u,v));
			while(x%j==0) x/=j;
		}
		if(x>1) we[x].pb(mp(u,v));
	}
	int sol=-1;
	for(int i=1;i<=n;i++) if(a[i]>1) sol=0;
    for(int i=2;i<N;i++) if(we[i].size())
	{
		for(int j=0;j<we[i].size();j++)
		{
			AddEdge(we[i][j].first,we[i][j].second);
		}
		ans=0;
		for(int j=0;j<wn[i].size();j++) if(!was[wn[i][j]])
		{
			DFS(wn[i][j],0);
		}
		sol=max(sol,ans);
		for(int j=0;j<wn[i].size();j++) was[wn[i][j]]=0;
	}
	printf("%i\n",sol+1);
	return 0;
}