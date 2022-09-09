#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int N=100050;
vector<int> E[N];
queue<int> q[2];
int c,in[N],col[N],sol;
int main()
{
	int n,m,u,v,i;
	scanf("%i %i",&n,&m);
	for(i=0;i<n;i++) scanf("%i",&col[i]);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[v].push_back(u);
		in[u]++;
	}
	for(i=0;i<n;i++) if(!in[i]) q[col[i]].push(i);
	while(!q[0].empty() || !q[1].empty())
	{
		if(q[c].empty()){ if(!c) sol++;c^=1;}
		u=q[c].front();
		q[c].pop();
		for(i=0;i<E[u].size();i++)
		{
			v=E[u][i];
			in[v]--;
			if(!in[v]) q[col[v]].push(v);
		}
	}
	printf("%i\n",sol);
	return 0;
}