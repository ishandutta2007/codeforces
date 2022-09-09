#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=150050;
vector<int> E[N];
bool ok=1,vis[N];
int cnt1,cnt2;
void DFS(int u)
{
	vis[u]=1;
	cnt1++;
	cnt2+=E[u].size();
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v);
	}
}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt1=cnt2=0;
			DFS(i);
			if((ll)cnt1*(cnt1-1)!=cnt2) return printf("NO\n"),0;
		}
	}
	printf("YES\n");
	return 0;
}