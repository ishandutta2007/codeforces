#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1050;
vector<int> E[N];
bool done[N];
int sz[N],a[N];
pair<int,int> b[N];
int c[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,m,u,v,i,j,sol=0;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		sol+=min(a[u],a[v]);
		E[u].push_back(v);
		E[v].push_back(u);
		sz[u]+=a[v];
		sz[v]+=a[u];
	}
	printf("%i\n",sol);
	for(i=1;i<=n;i++) c[i]=a[i]*E[i].size();//b[i].first=a[i]*E[i].size(),b[i].second=i;
	//sort(b+1,b+1+n);
	c[0]=-1;
	for(j=n;j;j--)
	{
		u=0;
		for(i=1;i<=n;i++) if(!done[i] && c[u]<c[i]) u=i;
		//u=b[j].second;
		sol+=sz[u];
		done[u]=1;
		for(i=0;i<E[u].size();i++)
		{
			v=E[u][i];
			sz[v]-=a[u];
			c[v]-=a[v];
		}
	}
	//printf("%i\n",sol);
	return 0;
}