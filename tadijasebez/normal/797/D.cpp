#include <stdio.h>
#include <map>
using namespace std;
map<int,int> Map;
const int N=100050;
int l[N],r[N],a[N],sol,par[N];
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
void DFS(int u, int Min, int Max)
{
	if(Min>=a[u] && Max<=a[u]) sol+=Map[a[u]],Map[a[u]]=0;
	if(l[u]) DFS(l[u],min(Min,a[u]),Max);
	if(r[u]) DFS(r[u],Min,max(Max,a[u]));
}
int main()
{
	int n,i,root;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&a[i],&l[i],&r[i]);
		Map[a[i]]++;
		if(l[i]==-1) l[i]=0;
		else par[l[i]]=i;
		if(r[i]==-1) r[i]=0;
		else par[r[i]]=i;
	}
	for(i=1;i<=n;i++) if(!par[i]) root=i;
	DFS(root,1e9+7,-1);
	printf("%i\n",n-sol);
	return 0;
}