#include <stdio.h>
#include <vector>
using namespace std;
const int N=1050;
vector<int> E[2][N];
bool vis[2][N];
void DFS(int u, int k)
{
	vis[k][u]=1;
	for(int i=0;i<E[k][u].size();i++)
	{
		int v=E[k][u][i];
		if(!vis[k][v]) DFS(v,k);
	}
}
char ch[52];
int main()
{
	int n,m,i,j,tr;
	scanf("%i %i",&n,&m);
	scanf("%s",ch);
	for(i=0;i<n;i++)
	{
		tr=i*m;
		for(j=1;j<m;j++)
		{
			if(ch[i]=='<')
			{
				E[0][tr+j+1].push_back(tr+j);
				E[1][tr+j].push_back(tr+j+1);
			}
			else
			{
				E[1][tr+j+1].push_back(tr+j);
				E[0][tr+j].push_back(tr+j+1);
			}
		}
	}
	scanf("%s",ch+1);
	for(i=1;i<=m;i++)
	{
		tr=i;
		for(j=1;j<n;j++)
		{
			if(ch[i]=='^')
			{
				E[0][tr+j*m].push_back(tr+(j-1)*m);
				E[1][tr+(j-1)*m].push_back(tr+j*m);
			}
			else
			{
				E[1][tr+j*m].push_back(tr+(j-1)*m);
				E[0][tr+(j-1)*m].push_back(tr+j*m);
			}
		}
	}
	DFS(1,0);
	DFS(1,1);
	for(i=1;i<=n*m;i++) if(!vis[0][i] || !vis[1][i]) return printf("NO\n"),0;
	printf("YES\n");
	return 0;
}