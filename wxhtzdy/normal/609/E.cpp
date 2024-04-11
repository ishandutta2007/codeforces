#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
	vector<int> edges;
	vector<long long> vals;
	int parent;
	long long value;
} Tree[200050];
vector<long long> ChainArray;
int ChainArrayIndex[200050];
int NodeChain[200050];
vector<int> HeadOfChain;
vector<int> euler;
vector<int> depthArray;
int logs[400050];
int SparseTable[400050][20];
int SubTreeSize[200050];
int FAI[200050];
void EulerWalk(int cur, int prev, int depth, long long val)
{
	Tree[cur].parent=prev;
	Tree[cur].value=val;
	FAI[cur]=euler.size();
	euler.push_back(cur);
	depthArray.push_back(depth);
	SubTreeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		long long w=Tree[cur].vals[i];
		if(v!=prev)
		{
			EulerWalk(v,cur,depth+1,w);
			SubTreeSize[cur]+=SubTreeSize[v];
			euler.push_back(cur);
			depthArray.push_back(depth);
		}
	}
}
void Preprocess()
{
	int i,k;
	k=0;
	for(i=0;i<400050;i++)
	{
		if(i==(1<<(k+1))) k++;
		logs[i]=k;
	}
}
void BuildSparseTable()
{
	Preprocess();
	EulerWalk(0,0,0,0);
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
void HeavyLightDecomposition(int cur, int prev)
{
	if(NodeChain[cur]==-1)
	{
		NodeChain[cur]=HeadOfChain.size();
		HeadOfChain.push_back(cur);
	}
	ChainArrayIndex[cur]=ChainArray.size();
	ChainArray.push_back(Tree[cur].value);
	int HeaviestChild=-1;
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		if(v!=prev)
		{
			if(HeaviestChild==-1 || SubTreeSize[HeaviestChild]<SubTreeSize[v])
				HeaviestChild=v;
		}
	}
	if(HeaviestChild!=-1)
	{
		NodeChain[HeaviestChild]=NodeChain[cur];
		HeavyLightDecomposition(HeaviestChild,cur);
		for(i=0;i<Tree[cur].edges.size();i++)
		{
			int v=Tree[cur].edges[i];
			if(v!=prev && v!=HeaviestChild)
			{
				HeavyLightDecomposition(v,cur);
			}
		}
	}
}
long long SegmentTree[800050];
const long long inf=1000000000;
long long max(long long a, long long b)
{
	if(a>b) return a;
	else return b;
}
void BuildSegmentTree(int ss, int se, int si)
{
	if(ss==se)
	{
		SegmentTree[si]=ChainArray[ss];
		return;
	}
	int mid=(ss+se)>>1;
	BuildSegmentTree(ss,mid,si*2);
	BuildSegmentTree(mid+1,se,si*2+1);
	SegmentTree[si]=max(SegmentTree[si*2],SegmentTree[si*2+1]);
}
long long Get(int ss, int se, int si, int qs, int qe)
{
	if(ss>qe || se<qs) return -inf;
	if(qs<=ss && qe>=se) return SegmentTree[si];
	int mid=(ss+se)>>1;
	return max(Get(ss,mid,si*2,qs,qe),Get(mid+1,se,si*2+1,qs,qe));
}
long long Get(int qs, int qe)
{
	if(ChainArrayIndex[qs]>ChainArrayIndex[qe])
	{
		int tmp=qs;
		qs=qe;
		qe=tmp;
	}
	return Get(0,ChainArray.size()-1,1,ChainArrayIndex[qs],ChainArrayIndex[qe]);
}
long long Get1(int qs, int qe)
{
	if(ChainArrayIndex[qs]>ChainArrayIndex[qe])
	{
		int tmp=qs;
		qs=qe;
		qe=tmp;
	}
	return Get(0,ChainArray.size()-1,1,ChainArrayIndex[qs]+1,ChainArrayIndex[qe]);
}
void HeavyLightDecomposition(int n)
{
	int i;
	for(i=0;i<n;i++) NodeChain[i]=-1;
	BuildSparseTable();
	HeavyLightDecomposition(0,0);
	BuildSegmentTree(0,ChainArray.size()-1,1);
}
struct Edge
{
	int u,v;
	long long w;
	int index;
	inline bool operator<(const Edge &b) const
	{
		return w<b.w;
	}
} edges[200050];
struct Subset
{
	int parent;
	int rank;
} subsets[200050];
int Find(int x)
{
	if(x!=subsets[x].parent)
		subsets[x].parent=Find(subsets[x].parent);
	return subsets[x].parent;
}
void Union(int u, int v)
{
	int x=Find(u);
	int y=Find(v);
	if(subsets[x].rank<subsets[y].rank)
	{
		subsets[x].parent=y;
	}
	else if(subsets[x].rank>subsets[y].rank)
	{
		subsets[y].parent=x;
	}
	else
	{
		subsets[y].parent=x;
		subsets[x].rank++;
	}
}
long long sol[200050];
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=0;i<n;i++)
	{
		subsets[i].parent=i;
		subsets[i].rank=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%i %i %lld",&edges[i].u,&edges[i].v,&edges[i].w);
		edges[i].u--;
		edges[i].v--;
		edges[i].index=i;
	}
	sort(edges,edges+m);
	int k=0;
	i=0;
	long long mst=0;
	while(k<n-1 && i<m)
	{
		int x=Find(edges[i].u);
		int y=Find(edges[i].v);
		if(x!=y)
		{
			k++;
			Union(x,y);
			mst+=edges[i].w;
			Tree[edges[i].u].edges.push_back(edges[i].v);
			Tree[edges[i].u].vals.push_back(edges[i].w);
			Tree[edges[i].v].edges.push_back(edges[i].u);
			Tree[edges[i].v].vals.push_back(edges[i].w);
			sol[edges[i].index]=-1;
		}
		i++;
	}
	HeavyLightDecomposition(n);
	for(i=0;i<m;i++)
	{
		if(sol[edges[i].index]==-1) sol[edges[i].index]=mst;
		else
		{
			int u=edges[i].u;
			int v=edges[i].v;
			int w=edges[i].w;
			long long tmp=0;
			int lca=LCA(u,v);
			while(NodeChain[u]!=NodeChain[lca])
			{
				tmp=max(tmp,Get(u,HeadOfChain[NodeChain[u]]));
				u=Tree[HeadOfChain[NodeChain[u]]].parent;
			}
			if(u!=lca) tmp=max(tmp,Get1(u,lca));
			while(NodeChain[v]!=NodeChain[lca])
			{
				tmp=max(tmp,Get(v,HeadOfChain[NodeChain[v]]));
				v=Tree[HeadOfChain[NodeChain[v]]].parent;
			}
			if(v!=lca) tmp=max(tmp,Get1(v,lca));
			sol[edges[i].index]=mst+w-tmp;
		}
	}
	for(i=0;i<m;i++) printf("%lld\n",sol[i]);
	return 0;
}