#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
const int M=4*N;
int x[M],ls[M],rs[M],Lazy[M],clock,root;
int te[N],b[N],e[N],Node[N];
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		x[c]=te[Node[ss]];
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]+x[rs[c]];
}
void Set(int c, int ss, int se, int qs, int qe)
{
	if(Lazy[c]==1)
	{
		x[c]=se-ss+1-x[c];
		if(ss!=se)
		{
			Lazy[ls[c]]^=1;
			Lazy[rs[c]]^=1;
		}
		Lazy[c]=0;
	}
	//printf("%i %i %i\n",x[c],ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		x[c]=se-ss+1-x[c];
		if(ss!=se)
		{
			Lazy[ls[c]]^=1;
			Lazy[rs[c]]^=1;
		}
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe);
	Set(rs[c],mid+1,se,qs,qe);
	x[c]=x[ls[c]]+x[rs[c]];
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(Lazy[c]==1)
	{
		x[c]=se-ss+1-x[c];
		if(ss!=se)
		{
			Lazy[ls[c]]^=1;
			Lazy[rs[c]]^=1;
		}
		Lazy[c]=0;
	}
	//printf("%i %i %i\n",x[c],ss,se);
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector<int> Tree[N];
int time;
void DFS(int cur, int prev)
{
	b[cur]=++time;
	Node[b[cur]]=cur;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur);
		}
	}
	e[cur]=time;
}
int main()
{
	int n,q,i,x;
	char t[5];
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i",&x),Tree[x].push_back(i);
	for(i=1;i<=n;i++) scanf("%i",&te[i]);
	DFS(1,0);
	Build(root,1,n);
	scanf("%i",&q);
	while(q --> 0)
	{
		scanf("%s %i",&t,&x);
		if(t[0]=='g') printf("%i\n",Get(root,1,n,b[x],e[x]));
		else Set(root,1,n,b[x],e[x]);
	}
	return 0;
}