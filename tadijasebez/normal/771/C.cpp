#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
long long Paths[5][2];
void Set(int x, int y)
{
	Paths[x][0]+=y;
	Paths[x][1]++;
}
vector<int> Tree[N];
int NodeSize[N];
bool vis[N];
void DFS(int cur, int prev, int &n)
{
	n++;
	NodeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !vis[v])
		{
			DFS(v,cur,n);
			NodeSize[cur]+=NodeSize[v];
		}
	}
}
int Find(int cur, int prev, int n)
{
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !vis[v])
		{
			if(NodeSize[v]>n/2) return Find(v,cur,n);
		}
	}
	return cur;
}
int Find(int src)
{
	int n=0;
	DFS(src,src,n);
	return Find(src,src,n);
}
long long sol;
int k;
void UpdateSol(int j, int l)
{
	//sol+=(path+k-1)/k;
	int i;
	for(i=0;i<k;i++)
	{
		sol+=Paths[i][0];
		sol+=Paths[i][1]*l;
		if(j+i==0) sol+=0;
		else if(j+i<=k) sol+=Paths[i][1];
		else sol+=Paths[i][1]*2;
		//sol+=Paths[i][1]*(((path%k)+i+k-1)/k);
	}
}
vector<int> back;
//bool ok=true;
void Solve(int cur, int prev, int path)
{
	UpdateSol(path%k,path/k);
	//if(ok) printf("\n%i %i",cur,sol);
	//if(cur==4) printf("\n%i %i %i %i\n",Paths[0][0],Paths[0][1],Paths[1][0],Paths[1][1]);
	back.push_back(path);
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !vis[v])
		{
			Solve(v,cur,path+1);
		}
	}
}
void Decompose(int src)
{
	src=Find(src);
	vis[src]=true;
	int i,j;
	for(i=0;i<k;i++) Paths[i][0]=0,Paths[i][1]=0;
	Set(0,0);
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!vis[v])
		{
			Solve(v,src,1);
			for(j=0;j<back.size();j++)
				Set(back[j]%k,back[j]/k);
			back.clear();
		}
	}
	//ok=false;
	//printf("%i %i\n",src,sol);
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!vis[v]) Decompose(v);
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
	printf("%lld\n",sol);
	return 0;
}