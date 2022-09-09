#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> Tree[N];
int Depth[N],End[N];
int ChainArrayIndex[N];
int time;
int SegmentTree[N<<2];
void Set(int ss, int se, int si, int qs, int qe, int x)
{
	if(qs>qe) return;
	if(se<qs || qe<ss) return;
	if(qs<=ss && qe>=se)
	{
		SegmentTree[si]+=x;
		return;
	}
	int mid=ss+se>>1;
	Set(ss,mid,si*2,qs,qe,x);
	Set(mid+1,se,si*2+1,qs,qe,x);
}
int A;
void Get(int ss, int se, int si, int qi)
{
	A+=SegmentTree[si];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Get(ss,mid,si*2,qi);
	else Get(mid+1,se,si*2+1,qi);
}
int MaxDepth=0;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
void DFS(int cur, int prev, int depth)
{
	MaxDepth=max(MaxDepth,depth);
	Depth[cur]=depth;
	ChainArrayIndex[cur]=time++;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur,depth+1);
		}
	}
	End[cur]=time;
}
int FenwickTree[N];
void Set(int x, int val)
{
	x++;
	x=min(x,MaxDepth+1);
	for(x;x>0;x-=x&-x) FenwickTree[x]+=val;
}
int Get(int x)
{
	x++;
	int ret=0;
	for(x;x<=MaxDepth+1;x+=x&-x) ret+=FenwickTree[x];
	return ret;
}
int main()
{
	int n,q,i,u,v,d,x,t;
	scanf("%i %i",&n,&q);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	for(i=0;i<Tree[1].size();i++)
	{
		DFS(Tree[1][i],1,1);
	}
	int qs,qe;
	while(q--)
	{
		scanf("%i",&t);
		if(t==0)
		{
			scanf("%i %i %i",&v,&x,&d);
			if(v==1)
			{
				Set(d,x);
			}
			else
			{
				Set(d-Depth[v],x);
				if(Depth[v]>d) qs=ChainArrayIndex[v]-d;
				else qs=ChainArrayIndex[v]+d-2*Depth[v]+1;
				qe=min(ChainArrayIndex[v]+d,End[v]-1);
				Set(0,time-1,1,qs,qe,x);
			}
		}
		else
		{
			scanf("%i",&v);
			if(v==1)
			{
				A=Get(0);
				printf("%i\n",A);
			}
			else
			{
				A=0;
				Get(0,time-1,1,ChainArrayIndex[v]);
				//printf("%i\n",A);
				A+=Get(Depth[v]);
				printf("%i\n",A);
			}
		}
	}
	return 0;
}