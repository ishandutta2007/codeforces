#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> E[N];
vector<int> cic;
bool mark[N];
int disc[N],time,par[N];
void DFS(int u, int p)
{
	disc[u]=++time;
	par[u]=p;
	//printf("%i %i\n",u,p);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p) continue;
		if(!disc[v]) DFS(v,u);
		else if(disc[v]<disc[u])
		{
			//printf("%i %i %i\n",v,p,u);
			int tmp=u;
			while(v!=tmp) cic.push_back(tmp),mark[tmp]=1,tmp=par[tmp];//,printf("%i ",u);
			cic.push_back(v);
			mark[v]=1;
			//printf("\n");
		}
	}
}
int dep[N];
void Calc(int u, int p)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p || mark[v]) continue;
		dep[v]=dep[u]+1;
		Calc(v,u);
	}
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1,0);
	for(i=0;i<cic.size();i++) Calc(cic[i],0);
	//for(i=0;i<cic.size();i++) printf("%i ",cic[i]);printf("\n");
	for(i=1;i<=n;i++) printf("%i ",dep[i]);
	return 0;
}