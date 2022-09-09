#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> Tree[N];
int CenParent[N];
int CenDepth[N];
int Depth[N][20];
int SubTree[N][20];
vector<int> DP[2][N];
int NodeSize[N];
bool visited[N];
bool mark[N];
int max(int a, int b){ return a>b?a:b;}
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
int Solve(int cur, int prev, int depth, int path, int cen)
{
	Depth[cur][depth]=path;
	SubTree[cur][depth]=DP[0][cen].size();
	int ret=0,i;
	if(mark[cur]) ret=path;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !visited[v])
		{
			ret=max(ret,Solve(v,cur,depth,path+1,cen));
		}
	}
	return ret;
}
int Decompose(int src, int depth)
{
	src=GetCen(src);
	visited[src]=true;
	CenDepth[src]=depth;
	int i;
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!visited[v])
		{
			int w=Solve(v,src,depth,1,src);
			DP[0][src].push_back(w);
			DP[1][src].push_back(w);
		}
	}
	SubTree[src][depth]=DP[0][src].size();
	for(i=1;i<DP[0][src].size();i++) 
		DP[0][src][i]=max(DP[0][src][i],DP[0][src][i-1]);
	for(i=DP[1][src].size()-2;i>=0;i--) 
		DP[1][src][i]=max(DP[1][src][i],DP[1][src][i+1]);
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!visited[v])
		{
			int New=Decompose(v,depth+1);
			CenParent[New]=src;
		}
	}
	return src;
}
int Get0(int p, int cen)
{
	if(p<0) return 0;
	return DP[0][cen][p];
}
int Get1(int p, int cen)
{
	if(p>=DP[1][cen].size()) return 0;
	return DP[1][cen][p];
}
int Query(int src, int x)
{
	int ans=0;
	int depth,sub,val;
	while(src!=0)
	{
		depth=CenDepth[src];
		sub=SubTree[x][depth];
		val=max(Get0(sub-1,src),Get1(sub+1,src));
		if(val==0 && !mark[src]) val=-Depth[x][depth];
		ans=max(ans,val+Depth[x][depth]);
		src=CenParent[src];
	}
	return ans;
}
int main()
{
	int n,m,k,i,u,v;
	scanf("%i %i %i",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%i",&u);
		mark[u]=true;
	}
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	Decompose(1,0);
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(Query(i,i)<=k) ans++;
	}
	printf("%i\n",ans);
	return 0;
}