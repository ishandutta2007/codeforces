#include <bits/stdc++.h>
using namespace std;
#define db double
#define pb push_back
const int N=405;
const int inf=1e9+7;
int dist[N][N];
db pro[N],dmx[N];
bool in[N];
vector<int> E[N];
void AddEdge(int u, int v){ E[u].pb(v);E[v].pb(u);dist[u][v]=dist[v][u]=1;}
int main()
{
	int n,m,i,j,k,u,v,d1,d2;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(i!=j) dist[i][j]=inf;
	for(i=1;i<=m;i++) scanf("%i %i",&u,&v),AddEdge(u,v);
	for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    db sol=0;
    for(u=1;u<=n;u++)
	{
		db ans=0;
		for(d1=0;d1<=n;d1++)
		{
			for(i=1;i<=n;i++) pro[i]=0,in[i]=0;
			vector<int> all;
			for(i=1;i<=n;i++) if(dist[u][i]==d1)
			{
				if(!in[i]) all.pb(i),in[i]=1;
				for(j:E[i])
				{
					if(!in[j]) all.pb(j),in[j]=1;
					pro[j]+=(db)1.0/n/E[i].size();
				}
			}
			if(all.empty()) continue;
			db mx=(db)1.0/n;
			for(v=1;v<=n;v++)
			{
				db tmp=0;
				for(i:all) dmx[dist[v][i]]=max(dmx[dist[v][i]],pro[i]);
				for(i:all) tmp+=dmx[dist[v][i]],dmx[dist[v][i]]=0;
				mx=max(mx,tmp);
			}
			ans+=mx;
		}
		sol=max(sol,ans);
	}
	cout << fixed << setprecision(12) << sol;
	return 0;
}