#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
long long min(long long a, long long b)
{
	if(a>b) return b;
	else return a;
}
const int N=200050;
const long long inf=10000000000000ll;
struct Edge
{
	int u,v,w;
	int t;
} Edges[2*N];
struct Node
{
	vector<int> edges;
	vector<int> vals;
	vector<int> EdgeIndex;
	int Parent;
	int ParentEdge;
	int BackEdge;
	long long Escape;
} Tree[N];
priority_queue<pair<int,int> > pq;
int FAI[N],LAI[N],cnt;
int SubTreeSize[N];
vector<int> ChainArray;
int ChainArrayIndex[N];
vector<int> HeadOfChain;
int NodeChain[N];
void EulerWalk(int cur, int prev, int depth)
{
	pq.push(make_pair(depth,cur));
	FAI[cur]=cnt++;
	SubTreeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		int w=Tree[cur].vals[i];
		int ei=Tree[cur].EdgeIndex[i];
		if(v!=prev)
		{
			Tree[v].Parent=cur;
			Tree[v].ParentEdge=w;
			Edges[ei].t=v;
			EulerWalk(v,cur,depth+1);
			SubTreeSize[cur]+=SubTreeSize[v];
		}
	}
	LAI[cur]=cnt++;
}
void HeavyLightDecomposition(int cur, int prev)
{
	if(NodeChain[cur]==-1)
	{
		NodeChain[cur]=HeadOfChain.size();
		HeadOfChain.push_back(cur);
	}
	ChainArrayIndex[cur]=ChainArray.size();
	ChainArray.push_back(Tree[cur].ParentEdge);
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
long long SegmentTree[N*4];
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
	SegmentTree[si]=SegmentTree[si*2]+SegmentTree[si*2+1];
}
void Set(int ss, int se, int si, int qi, int val)
{
	if(ss>qi || se<qi) return;
	if(ss==se && ss==qi)
	{
		SegmentTree[si]=val;
		return;
	}
	int mid=(ss+se)>>1;
	Set(ss,mid,si*2,qi,val);
	Set(mid+1,se,si*2+1,qi,val);
	SegmentTree[si]=SegmentTree[si*2]+SegmentTree[si*2+1];
}
void Set(int qi, int val)
{
	Set(0,ChainArray.size()-1,1,ChainArrayIndex[qi],val);
}
long long Get(int ss, int se, int si, int qs, int qe)
{
	if(ss>qe || se<qs) return 0;
	if(qs<=ss && qe>=se) return SegmentTree[si];
	int mid=(ss+se)>>1;
	return Get(ss,mid,si*2,qs,qe)+Get(mid+1,se,si*2+1,qs,qe);
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
void SetEscape(int n)
{
	while(!pq.empty())
	{
		int x=pq.top().second;
		pq.pop();
		if(x==0) continue;
		Tree[Tree[x].Parent].Escape=min(Tree[Tree[x].Parent].Escape,min(Tree[x].Escape,Tree[x].BackEdge)+Tree[x].ParentEdge);
	}
}
void HeavyLightDecomposition(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		Tree[i].Escape=inf;
		NodeChain[i]=-1;
	}
	EulerWalk(0,0,1);
	HeavyLightDecomposition(0,0);
	BuildSegmentTree(0,n-1,1);
	SetEscape(n);
}
void UpdateEscape(int u)
{
	while(u!=0)
	{
		int v=Tree[u].Parent;
                long long tmp=inf;
                int i;
                for(i=0;i<Tree[v].edges.size();i++)
{
int f=Tree[v].edges[i];
if(f!=Tree[v].Parent)
tmp=min(tmp,min(Tree[f].BackEdge,Tree[f].Escape)+Tree[f].ParentEdge);
}
Tree[v].Escape=tmp;
u=v;
		/*if(Tree[v].Escape>min(Tree[u].Escape,Tree[u].BackEdge)+Tree[u].ParentEdge)
		{
			Tree[v].Escape=min(Tree[u].Escape,Tree[u].BackEdge)+Tree[u].ParentEdge;
			u=v;
		}
		else break;*/
	}
}
long long Dist(int u)
{
	long long sum=0;
	while(NodeChain[u]!=NodeChain[0])
	{
		sum+=Get(HeadOfChain[NodeChain[u]],u);
		u=Tree[HeadOfChain[NodeChain[u]]].Parent;
	}
	sum+=Get(0,u);
	return sum;
}
int main()
{
	int n,i,u,v,w,q,t,j=0;
	scanf("%i %i",&n,&q);
	for(i=0;i<n-1;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		u--;
		v--;
		Edges[i].u=u;
		Edges[i].v=v;
		Edges[i].w=w;
		Tree[u].edges.push_back(v);
		Tree[u].vals.push_back(w);
		Tree[u].EdgeIndex.push_back(i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		u--;
		v--;
		Edges[n-1+i].u=u;
		Edges[n-1+i].v=v;
		Edges[n-1+i].w=w;
		Tree[u].BackEdge=w;
	}
	HeavyLightDecomposition(n);
	while(q--)
	{
		j++;
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&i,&w);
			i--;
			if(i<n-1)
			{
				Tree[Edges[i].v].ParentEdge=w;
				Set(Edges[i].v,w);
				UpdateEscape(Edges[i].v);
			}
			else
			{
				Tree[Edges[i].u].BackEdge=w;
				UpdateEscape(Edges[i].u);
			}
		}
		if(t==2)
		{
			scanf("%i %i",&u,&v);
			u--;
			v--;
			if(u==v) printf("0\n");
			else
			{
				long long dist1=Dist(u);
				long long dist2=Dist(v);
				long long sol=inf;
				if(FAI[u]<FAI[v] && LAI[u]>LAI[v])
				{
					sol=dist2-dist1;
				}
				else sol=dist2+min(Tree[u].Escape,Tree[u].BackEdge);
				printf("%lld\n",sol);
			}
		}
	}
	return 0;
}