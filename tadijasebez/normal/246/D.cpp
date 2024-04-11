#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
vector<int> E[N];
int c[N],sol=-1,taj;
bool vis[N];
int main()
{
	int n,m,u,v,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&c[i]),vis[c[i]]=1;
	while(m--)
	{
		scanf("%i %i",&u,&v);
		if(c[u]==c[v]) continue;
		E[c[u]].push_back(c[v]);
		E[c[v]].push_back(c[u]);
	}
	for(i=1;i<N;i++)
	{
		if(vis[i])
		{
			sort(E[i].begin(),E[i].end());
			E[i].erase(unique(E[i].begin(),E[i].end()),E[i].end());
			if(sol<(signed)E[i].size())
			{
				taj=i;
				sol=E[i].size();
			}
		}
	}
	printf("%i\n",taj);
	return 0;
}