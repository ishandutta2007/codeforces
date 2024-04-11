#include <stdio.h>
#include <vector>
using namespace std;
const int N=7050;
int in[N][2],n;
vector<int> s[2];
bool was[N][2],lose[N][2],win[N][2];
void DFS(int u, int t)
{
	was[u][t]=1;
	for(int i=0;i<s[t^1].size();i++)
	{
		int v=(u-s[t^1][i]+n)%n;
		if(!was[v][t^1])
		{
			if(lose[u][t])
			{
				win[v][t^1]=1;
				DFS(v,t^1);
			}
			else
			{
				in[v][t^1]--;
				if(!in[v][t^1])
				{
					lose[v][t^1]=1;
					DFS(v,t^1);
				}
			}
		}
	}
}
int main()
{
	int k,x,i;
	scanf("%i",&n);
	scanf("%i",&k);while(k--) scanf("%i",&x),s[0].push_back(x);
	scanf("%i",&k);while(k--) scanf("%i",&x),s[1].push_back(x);
	lose[0][0]=lose[0][1]=1;
	for(i=1;i<n;i++) in[i][0]=s[0].size(),in[i][1]=s[1].size();
	DFS(0,0);DFS(0,1);
	for(i=1;i<n;i++)
	{
		if(win[i][0]) printf("Win ");
		else if(lose[i][0]) printf("Lose ");
		else printf("Loop ");
	}
	printf("\n");
	for(i=1;i<n;i++)
	{
		if(win[i][1]) printf("Win ");
		else if(lose[i][1]) printf("Lose ");
		else printf("Loop ");
	}
	printf("\n");
	return 0;
}