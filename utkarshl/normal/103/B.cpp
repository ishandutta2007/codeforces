#include"stdio.h"
#include"vector"
#include"queue"
using namespace std;
int status[101];
bool bfs(vector<int> G[],int n)
{
	for(int x=0;x<n;x++)status[x]=0;
	status[0]=1;
	queue<int> q;
	q.push(0);
	int ct=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int y=0;y<G[x].size();y++)
			if(status[G[x][y]]==0)
			{
				status[G[x][y]]=1;
				ct++;
				q.push(G[x][y]);
			}
	}
	return n==ct;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> G[n];
	if(m!=n){printf("NO");return 0;}
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(bfs(G,n))
	{
		printf("FHTAGN!");
	}
	else
	{
		printf("NO");
	}
}