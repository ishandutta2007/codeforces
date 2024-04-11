#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#define ll long long
const int N=32;
vector<int> E[N];
ll x[N],y[N];
int n;
int nx[4]={0,1,0,-1};
int ny[4]={1,0,-1,0};
void DFS(int u, int p, int d, int dir)
{
	if(E[u].size()>4)
	{
		printf("NO\n");
		exit(0);
	}
	int j=0;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p) continue;
		if(j==dir) j++;
		x[v]=x[u]+(((ll)1)<<(n-d))*nx[j];
		y[v]=y[u]+(((ll)1)<<(n-d))*ny[j];
		DFS(v,u,d+1,(j+2)%4);
		j++;
	}
}
int main()
{
	int i,u,v;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1,0,0,-1);
	printf("YES\n");
	for(i=1;i<=n;i++) printf("%lld %lld\n",x[i],y[i]);
	return 0;
}