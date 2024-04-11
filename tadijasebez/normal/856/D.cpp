#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
const int M=N*20;
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{//printf("%i %i %i %i\n",ss,se,qs,qe);
	if(qe<qs) return 0;
	if(ss>qe || se<qs) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector<int> Tree[N];
int NodeSize[N],Index[N],NodeChain[N],time,par[N];
vector<int> HeadOfChain;
vector<int> Euler,Depth;
int logs[N<<1],SparseTable[N<<1][20],FAI[N];
void EulerWalk(int cur, int prev, int depth)
{
	par[cur]=prev;
	FAI[cur]=Euler.size();
	Euler.push_back(cur);
	Depth.push_back(depth);
	NodeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			EulerWalk(v,cur,depth+1);
			NodeSize[cur]+=NodeSize[v];
			Euler.push_back(cur);
			Depth.push_back(depth);
		}
	}
}
void Preprocess()
{
	int i,k=0;
	for(i=0;i<N<<1;i++)
	{
		if(i==1<<k+1) k++;
		logs[i]=k;
	}
}
void BuildSparseTable()
{
	EulerWalk(1,0,1);
	Preprocess();
	int n=Euler.size(),i,j;
	for(i=0;i<n;i++) SparseTable[i][0]=i;
	for(j=1;j<20;j++)
	{
		for(i=0;i<=n-(1<<j)+1;i++)
		{
			if(Depth[SparseTable[i][j-1]]<Depth[SparseTable[i+(1<<(j-1))][j-1]])
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
	if(Depth[SparseTable[u][k]]<Depth[SparseTable[v-(1<<k)][k]])
		return Euler[SparseTable[u][k]];
	else return Euler[SparseTable[v-(1<<k)][k]];
}
void HeavyLightDecomposition(int cur, int prev)
{
	if(NodeChain[cur]==-1)
	{
		NodeChain[cur]=HeadOfChain.size();
		HeadOfChain.push_back(cur);
	}
	Index[cur]=++time;
	int HeaviestChild=-1,i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			if(HeaviestChild==-1 || NodeSize[HeaviestChild]<NodeSize[v])
				HeaviestChild=v;
		}
	}
	if(HeaviestChild!=-1)
	{
		NodeChain[HeaviestChild]=NodeChain[cur];
		HeavyLightDecomposition(HeaviestChild,cur);
		for(i=0;i<Tree[cur].size();i++)
		{
			int v=Tree[cur][i];
			if(v!=prev && v!=HeaviestChild)
			{
				HeavyLightDecomposition(v,cur);
			}
		}
	}
}
void Decompose(int n)
{
	int i;
	for(i=1;i<=n;i++) NodeChain[i]=-1;
	HeavyLightDecomposition(1,0);
}
struct Query
{
	int u,v,w;
	Query(){}
	Query(int a, int b, int c){ u=a,v=b,w=c;}
};
vector<Query> Jobs[N];
int Sum[N],Best[N],n;
int max(int a, int b){ return a>b?a:b;}
void Solve(int cur, int prev)
{	//printf("%i %i\n",Index[cur],NodeChain[cur]);
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			Solve(v,cur);
		}
	}
	Best[cur]=Sum[cur];
	for(i=0;i<Jobs[cur].size();i++)
	{
		//printf("%i",cur);
		int u=Jobs[cur][i].u;
		int v=Jobs[cur][i].v;
		int w=Jobs[cur][i].w;
		int tmp=0;
		while(NodeChain[u]!=NodeChain[cur])
		{
			//printf(":D");
			tmp+=Get(root,1,n,Index[HeadOfChain[NodeChain[u]]],Index[u]);
			u=par[HeadOfChain[NodeChain[u]]];
		}
		tmp+=Get(root,1,n,Index[cur]+1,Index[u]);
		while(NodeChain[v]!=NodeChain[cur])
		{
			tmp+=Get(root,1,n,Index[HeadOfChain[NodeChain[v]]],Index[v]);
			v=par[HeadOfChain[NodeChain[v]]];
		}
		tmp+=Get(root,1,n,Index[cur]+1,Index[v]);
		//printf("%i %i %i %i %i %i\n",cur,u,v,w,tmp,Sum[cur]);
		Best[cur]=max(Best[cur],Sum[cur]+tmp+w);
	}
	Set(root,1,n,Index[cur],Sum[cur]-Best[cur]);
	Sum[prev]+=Best[cur];
}
int main()
{
	int q,i,u,v,w;
	scanf("%i %i",&n,&q);
	for(u=2;u<=n;u++)
	{
		scanf("%i",&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	BuildSparseTable();
	while(q--)
	{
		scanf("%i %i %i",&u,&v,&w);
		Jobs[LCA(u,v)].push_back(Query(u,v,w));
		//printf("%i\n",LCA(u,v));
	}
	Decompose(n);
	//for(i=1;i<=n;i++) printf("%i ",Index[i]);
	//printf("\n");
	Solve(1,0);
	printf("%i\n",Best[1]);
	return 0;
}