#include <stdio.h>
#include <queue>
using namespace std;
#define ll long long
queue<int> qx,qy;
const int N=20000050;
const ll inf=9e18;
ll min(ll a, ll b){ return a>b?b:a;}
ll dist[N];
bool vis[N];
int main()
{
	int x,y,n,i,u;
	scanf("%i %i %i",&n,&x,&y);
	for(i=0;i<=2*n;i++) dist[i]=inf;
	dist[0]=0;qx.push(0);
	while(qx.size() || qy.size())
	{
		if(qx.empty()) u=qy.front(),qy.pop();
		else if(qy.empty()) u=qx.front(),qx.pop();
		else if(dist[qx.front()]<dist[qy.front()]) u=qx.front(),qx.pop();
		else u=qy.front(),qy.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(u==n) break;
		if(u-1>0 && dist[u-1]>dist[u]+x)
		{
			qx.push(u-1);
			dist[u-1]=dist[u]+x;
		}
		if(u+1<=2*n && dist[u+1]>dist[u]+x)
		{
			qx.push(u+1);
			dist[u+1]=dist[u]+x;
		}
		if(u*2<=2*n && dist[u*2]>dist[u]+y)
		{
			qy.push(u*2);
			dist[u*2]=dist[u]+y;
		}
	}
	printf("%lld\n",dist[n]);
	return 0;
}