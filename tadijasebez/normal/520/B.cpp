#include <stdio.h>
#include <queue>
using namespace std;
const int N=10050;
queue<int> q;
int dist[N];
bool vis[N];
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	q.push(n);
	vis[n]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x>1 && !vis[x-1]) vis[x-1]=1,dist[x-1]=dist[x]+1,q.push(x-1);
		if(x*2<N && !vis[x*2]) vis[x*2]=1,dist[x*2]=dist[x]+1,q.push(x*2);
	}
	printf("%i\n",dist[m]);
	return 0;
}