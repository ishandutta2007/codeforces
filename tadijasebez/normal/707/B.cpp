#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector< pair<int,int> > E[N];
int min(int a, int b){ return a>b?b:a;}
bool done[N];
int a[N],sol=1e9+1e8;
int main()
{
	int n,m,k,i,u,v,w,j;
	scanf("%i %i %i",&n,&m,&k);
	while(m--)
	{
		scanf("%i %i %i",&u,&v,&w);
		E[u].push_back(make_pair(v,w));
		E[v].push_back(make_pair(u,w));
	}
	for(i=1;i<=k;i++) scanf("%i",&a[i]),done[a[i]]=1;
	for(i=1;i<=k;i++)
	{
		u=a[i];
		for(j=0;j<E[u].size();j++)
		{
			v=E[u][j].first;
			w=E[u][j].second;
			if(!done[v]) sol=min(sol,w);
		}
	}
	if(sol!=1e9+1e8) printf("%i\n",sol);
	else printf("-1\n");
	return 0;
}