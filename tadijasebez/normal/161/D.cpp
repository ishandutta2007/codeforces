#include <stdio.h>
#include <vector>
using namespace std;
const int N=50050;
vector<int> Tree[N];
bool visited[N];
int NodeSize[N];
void DFS(int cur, int prev, int &n)
{
	n++;
	NodeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !visited[v])
		{
			DFS(v,cur,n);
			NodeSize[cur]+=NodeSize[v];
		}
	}
}
int GetCen(int cur, int prev, int n)
{
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !visited[v])
		{
			if(NodeSize[v]>n/2) return GetCen(v,cur,n);
		}
	}
	return cur;
}
int GetCen(int src)
{
	int n=0;
	DFS(src,src,n);
	return GetCen(src,src,n);
}
vector<int> Track,Backtrack;
int dp[N];
int k,sol;
void Solve(int cur, int prev, int depth)
{
	if(depth==k) sol++;
	if(depth<k) sol+=dp[k-depth];
	Track.push_back(depth);
	Backtrack.push_back(depth);
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !visited[v])
		{
			Solve(v,cur,depth+1);
		}
	}
}
void Decompose(int src)
{
	src=GetCen(src);
	visited[src]=true;
	int i,j;
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!visited[v])
		{
			Solve(v,src,1);
			for(j=0;j<Backtrack.size();j++)
			{
				dp[Backtrack[j]]++;
			}
			Backtrack.clear();
		}
	}
	for(j=0;j<Track.size();j++)
	{
		dp[Track[j]]=0;
	}
	Track.clear();
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!visited[v])
		{
			Decompose(v);
		}
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i %i",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	Decompose(1);
	printf("%i\n",sol);
	return 0;
}