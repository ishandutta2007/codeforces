#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
int Need[N];
vector<int> S[N],E[N];
int cnt1,cnt2;
bool vis[N];
vector<int> tmp,sol;
int min(int a, int b){ return a>b?b:a;}
void DFS(int u)
{
	vis[u]=1;
	tmp.push_back(u);
	cnt1+=(Need[u]==1);
	cnt2+=(Need[u]==2);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v);
	}
}
int big[N];
int main()
{
	int n,m,l,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&l);
		while(l--) scanf("%i",&j),S[i].push_back(j);
	}
	for(i=2;i<=n;i++)
	{
		int k=min(S[i].size(),S[i-1].size());
		j=0;
		while(j<k && S[i][j]==S[i-1][j]) j++;
		if(j==k && S[i].size()<S[i-1].size()) return printf("No\n"),0;
		if(j!=k)
		{
			if(S[i][j]<S[i-1][j])
			{
				Need[S[i-1][j]]=1;
				Need[S[i][j]]=2;
			}
			else
			{
				E[S[i][j]].push_back(S[i-1][j]);
				//E[S[i-1][j]].push_back(S[i][j]);
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		if(Need[i]==1 && !vis[i])
		{
			tmp.clear();
			cnt2=0;
			DFS(i);
			if(cnt2) return printf("No\n"),0;
			for(j=0;j<tmp.size();j++) sol.push_back(tmp[j]);
		}
		/*if(!vis[i])
		{
			cnt1=0;
			cnt2=0;
			tmp.clear();
			DFS(i);
			if(cnt1 && cnt2) return printf("No\n"),0;
			if(cnt1)
			{
				for(j=0;j<tmp.size();j++) sol.push_back(tmp[j]);
			}
		}*/
	}
	for(i=0;i<sol.size();i++)
	{
		big[sol[i]]=1;
	}
	for(i=2;i<=n;i++)
	{
		int k=min(S[i].size(),S[i-1].size());
		j=0;
		while(j<k && S[i][j]==S[i-1][j]) j++;
		if(j==k && S[i].size()<S[i-1].size()) return printf("No\n"),0;
		if(j!=k)
		{
			if(big[S[i][j]] && !big[S[i-1][j]]) return printf("No\n"),0;
			if(big[S[i][j]]==big[S[i-1][j]] && S[i][j]<S[i-1][j]) return printf("No\n"),0;
		}
	}
	printf("Yes\n");
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	return 0;
}