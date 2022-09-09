#include <stdio.h>
#include <vector>
using namespace std;
struct Node
{
	vector<int> edges;
	int depth;
} Tree[100050];
int FAI[100050];
vector<int> euler;
vector<int> depthArray;
int logs[200050];
int SparseTable[200050][20];
void EulerWalk(int cur, int prev, int depth)
{
	FAI[cur]=euler.size();
	euler.push_back(cur);
	depthArray.push_back(depth);
	Tree[cur].depth=depth;
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		if(v!=prev)
		{
			EulerWalk(v,cur,depth+1);
			euler.push_back(cur);
			depthArray.push_back(depth);
		}
	}
}
void Preprocess()
{
	int i,k=0;
	for(i=0;i<200050;i++)
	{
		if(i==(1<<(k+1))) k++;
		logs[i]=k;
	}
}
void BuildSparseTable()
{
	Preprocess();
	EulerWalk(0,0,1);
	int n=euler.size(),i,j;
	for(i=0;i<n;i++) SparseTable[i][0]=i;
	for(j=1;j<20;j++)
	{
		for(i=0;i<n-(1<<j)+1;i++)
		{
			if(depthArray[SparseTable[i][j-1]]<depthArray[SparseTable[i+(1<<(j-1))][j-1]])
				SparseTable[i][j]=SparseTable[i][j-1];
			else SparseTable[i][j]=SparseTable[i+(1<<(j-1))][j-1];
		}
	}
}
int LCA(int u, int v)
{
	if(FAI[u]>FAI[v])
	{
		int tmp=u;
		u=v;
		v=tmp;
	}
	u=FAI[u];
	v=FAI[v]+1;
	int k=logs[v-u];
	if(depthArray[SparseTable[u][k]]<depthArray[SparseTable[v-(1<<k)][k]])
		return euler[SparseTable[u][k]];
	else return euler[SparseTable[v-(1<<k)][k]];
}
int Dist(int u, int v)
{
	int lca=LCA(u,v);
	int res=Tree[u].depth+Tree[v].depth-2*Tree[lca].depth+1;
	return res;
}
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int max(int a, int b, int c)
{
	return max(a,max(b,c));
}
int main()
{
	int n,q,i,j,u,a,b,c;
	scanf("%i%i",&n,&q);
	for(i=1;i<=n-1;i++)
	{
		scanf("%i",&u);
		u--;
		Tree[u].edges.push_back(i);
		Tree[i].edges.push_back(u);
	}
	BuildSparseTable();
	int lca1,lca2,lca3,lca;
	while(q--)
	{
		scanf("%i %i %i",&a,&b,&c);
		a--;
		b--;
		c--;
		lca1=LCA(a,b);
		lca=lca1;
		lca2=LCA(b,c);
		if(Tree[lca].depth<Tree[lca2].depth) lca=lca2;
		lca3=LCA(a,c);
		if(Tree[lca].depth<Tree[lca3].depth) lca=lca3;
		//printf("%i ",lca);
		printf("%i\n",max(Dist(lca,a),Dist(lca,b),Dist(lca,c)));
	}
	//printf("%i\n",Dist(0,1));
	return 0;
}
/*
input:

3 2
1 1
1 2 3
2 3 3

output:

2
3

input:

4 1
1 2 3
1 2 3

output:

2
*/