#include <stdio.h>
#include <vector>
using namespace std;
const int N=500050;
const int S=1<<19;
int SegTree[S<<1],Lazy[S<<1];
void Set(int si, int ss, int se, int qi)
{
	if(Lazy[si]==1)
	{
		SegTree[si]=(se-ss+1);
		if(ss!=se)
		{
			Lazy[si*2]=1;
			Lazy[si*2+1]=1;
		}
		Lazy[si]=0;
	}
	SegTree[si]--;
	if(SegTree[si]<0) SegTree[si]=0;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(si*2,ss,mid,qi);
	else Set(si*2+1,mid+1,se,qi);
}
void Set(int si, int ss, int se, int qs, int qe)
{
	if(Lazy[si]==1)
	{
		SegTree[si]=(se-ss+1);
		if(ss!=se)
		{
			Lazy[si*2]=1;
			Lazy[si*2+1]=1;
		}
		Lazy[si]=0;
	}
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		SegTree[si]=(se-ss+1);
		if(ss!=se)
		{
			Lazy[si*2]=1;
			Lazy[si*2+1]=1;
		}
		return;
	}
	int mid=ss+se>>1;
	Set(si*2,ss,mid,qs,qe);
	Set(si*2+1,mid+1,se,qs,qe);
	SegTree[si]=SegTree[si*2]+SegTree[si*2+1];
}
int Get(int si, int ss, int se, int qs, int qe)
{
	if(Lazy[si]==1)
	{
		SegTree[si]=(se-ss+1);
		if(ss!=se)
		{
			Lazy[si*2]=1;
			Lazy[si*2+1]=1;
		}
		Lazy[si]=0;
	}
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return SegTree[si];
	int mid=ss+se>>1;
	return Get(si*2,ss,mid,qs,qe)+Get(si*2+1,mid+1,se,qs,qe);
}
vector<int> Tree[N];
int b[N],e[N],time,par[N];
void DFS(int cur, int prev, int depth)
{
	b[cur]=++time;
	par[cur]=prev;
	int i;
	//if(depth>20) for(i=0;i<10;i++) par[cur]=par[par[cur]];
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur,depth+1);
		}
	}
	e[cur]=time;
}
//bool mark[N];
void Query2(int x);
bool Query3(int x);
void Query1(int x)
{
	//if(mark[x])
	//{
	//	mark[x]=false;
	//	if(Get(1,0,S-1,b[x],b[x])==1 && x>1)
	//		Query2(par[x]);
	//}
	if(x>1 && !Query3(x))
		Query2(par[x]);
	Set(1,0,S-1,b[x],e[x]);
}
void Query2(int x)
{
	//mark[x]=true;
	Set(1,0,S-1,b[x]);
}
bool Query3(int x)
{
	return Get(1,0,S-1,b[x],e[x])==(e[x]-b[x]+1);
}
int main()
{
	int n,i,u,v,q,t;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	DFS(1,0,1);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&t,&u);
		if(t==1) Query1(u);
		if(t==2) Query2(u);
		if(t==3) printf("%i\n",Query3(u));
	}
	return 0;
}