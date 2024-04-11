#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=200050;
const int inf=1e9+7;
vector<int> bck[N];int mul[N],dist[N];
vector<pair<int,int> > E[N];
bool use[N];
int main()
{
	int n,m,u,v,i,k,pro=1,e,mask;
	scanf("%i %i %i",&n,&m,&k);
	for(i=0;i<m;i++) scanf("%i %i",&u,&v),E[u].pb(mp(v,i)),E[v].pb(mp(u,i));
	for(i=1;i<=n;i++) dist[i]=inf;
	queue<int> q;
	q.push(1);dist[1]=0;
	while(q.size())
	{
		u=q.front();q.pop();
		for(i=0;i<E[u].size();i++)
		{
			v=E[u][i].first;
			e=E[u][i].second;
			if(dist[v]>dist[u]+1)
			{
				bck[v].clear();
				dist[v]=dist[u]+1;
				q.push(v);
			}
			if(dist[v]==dist[u]+1) bck[v].pb(e);
		}
	}
	for(i=2;i<=n;i++)
	{
		mul[i]=bck[i].size();
		if(k<(ll)pro*mul[i]) pro=k;
		else pro*=mul[i];
	}
	printf("%i\n",pro);
	for(mask=0;mask<pro;mask++)
	{
		for(i=0;i<m;i++) use[i]=0;
		int tmp=mask;
		for(i=2;i<=n;i++)
		{
			use[bck[i][tmp%mul[i]]]=1;
			tmp/=mul[i];
		}
		for(i=0;i<m;i++) printf("%i",use[i]);printf("\n");
	}
	return 0;
}