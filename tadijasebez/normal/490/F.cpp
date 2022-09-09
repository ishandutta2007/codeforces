#include <stdio.h>
#include <vector>
using namespace std;
const int N=6050;
int sol,sz,r[N];
vector<int> E[N];
vector<int> a[N];
int max(int a, int b){ return a>b?a:b;}
void DFS(int u, int p)
{
	int top=sz-1,bot=0,ans=sz,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(a[mid].back()>=r[u]) ans=mid,top=mid-1;
		else bot=mid+1;
	}
	if(ans==sz) sz++;
	a[ans].push_back(r[u]);
	sol=max(sol,sz);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
	a[ans].pop_back();
	if(a[ans].empty()) sz--;
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&r[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(i=1;i<=n;i++) DFS(i,0);
	printf("%i\n",sol);
	return 0;
}