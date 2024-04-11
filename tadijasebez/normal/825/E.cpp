#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N=100050;
priority_queue<int> pq;
vector<int> E[N];
int in[N],sol[N],cnt;
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	cnt=n;
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[v].push_back(u);
		in[u]++;
	}
	for(i=1;i<=n;i++) if(!in[i]) pq.push(i);
	while(!pq.empty())
	{
		u=pq.top();
		pq.pop();
		sol[u]=cnt--;
		for(i=0;i<E[u].size();i++)
		{
			v=E[u][i];
			in[v]--;
			if(!in[v]) pq.push(v);
		}
	}
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	return 0;
}