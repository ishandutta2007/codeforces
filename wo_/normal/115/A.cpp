#include<cstdio>
#include<vector>

using namespace std;

vector<int> tops;
vector<int> G[2200];

int dep[2200];

void dfs(int v,int p,int de)
{
	dep[v]=de;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v,de+1);
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int in;
		scanf("%d",&in);
		if(in==-1) tops.push_back(i);
		else G[in-1].push_back(i);
	}
	for(int i=0;i<tops.size();i++) dfs(tops[i],-1,1);
	int ans=1;
	for(int i=0;i<N;i++) ans=max(ans,dep[i]);
	printf("%d\n",ans);
	return 0;
}