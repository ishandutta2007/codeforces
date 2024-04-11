#include<cstdio>
#include<vector>

using namespace std;

vector<int> G[110];

int cnt;
bool loop;
bool used[110]={};

void dfs(int v,int prev,int origin)
{
	used[v]=true;
	cnt++;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==prev) continue;
		if(used[G[v][i]]==true)
		{
			loop=true;
			return;
		}
		dfs(G[v][i],v,origin);
	}
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int a=0;
	for(int i=0;i<N;i++)
	{
		if(used[i]==true) continue;
		cnt=0;loop=false;
		dfs(i,-1,i);
		if(loop==true)
		{
			if(cnt%2==1) a++;
		}
	}
	if((N-a)%2==1) a++;
	printf("%d\n",a);
	return 0;
}