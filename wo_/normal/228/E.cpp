#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> G[220];//i:send to i,i+N:not send to i
int cmp[220];

vector<int> vs;
bool used[220];

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(used[G[v][i]]==true) continue;
		dfs(G[v][i]);
	}
	vs.push_back(v);
}

int now=0;

void rdfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)//rG is same as G
	{
		if(used[G[v][i]]==true) continue;
		rdfs(G[v][i]);
	}
	cmp[v]=now;
}

vector<int> ans;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		if(c==1)
		{
			G[a].push_back(b);
			G[b].push_back(a);
			G[a+N].push_back(b+N);
			G[b+N].push_back(a+N);
		}
		else
		{
			G[a].push_back(b+N);
			G[b].push_back(a+N);
			G[a+N].push_back(b);
			G[b+N].push_back(a);
		}
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<2*N;i++)
	{
		if(used[i]==false) dfs(i);
	}
	memset(used,false,sizeof(used));
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(used[vs[i]]==true) continue;
		rdfs(vs[i]);
		now++;
	}
	for(int i=0;i<N;i++)
	{
		if(cmp[i]==cmp[i+N])
		{
			printf("Impossible\n");
			return 0;
		}
	}
	for(int i=0;i<N;i++)
	{
		if(cmp[i+N]<cmp[i]) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d%c",ans[i]+1,i==ans.size()-1?'\n':' ');
	}
	return 0;
}