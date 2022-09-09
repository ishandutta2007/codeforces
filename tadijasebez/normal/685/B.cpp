#include <stdio.h>
#include <vector>
using namespace std;
const int N=300050;
vector<int> Tree[N];
int b[N],e[N],time,NodeSize[N],ChildSize[N],Node[N];
int max(int a, int b){ return a>b?a:b;}
void DFS(int cur, int prev)
{
	b[cur]=++time;
	Node[b[cur]]=cur;
	NodeSize[cur]=1;
	ChildSize[cur]=0;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur);
			NodeSize[cur]+=NodeSize[v];
			ChildSize[cur]=max(ChildSize[cur],NodeSize[v]);
		}
	}
	e[cur]=time;
}
const int M=N*40;
int x[M],ls[M],rs[M],root[N][2],clock;
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++clock,x[c]=x[p]^val,ls[c]=ls[p],rs[c]=rs[p];
	if(ss==se)  return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int Get(int p, int c, int ss, int se, int qs, int qe)
{
	//printf("%i %i\n",ss,se);
	if(qs>qe) return 0;
	if(qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return x[p]^x[c];
	int mid=ss+se>>1;
	return Get(ls[p],ls[c],ss,mid,qs,qe)^Get(rs[p],rs[c],mid+1,se,qs,qe);
}
int n;
void Set()
{
	int i;
	for(i=1;i<=n;i++)
	{
		Set(root[i-1][0],root[i][0],0,n,NodeSize[Node[i]],Node[i]);
		Set(root[i-1][1],root[i][1],0,n,ChildSize[Node[i]],Node[i]);
	}
}
int Query(int x)
{
	int sz=(NodeSize[x]+1)/2-1;
	int ans=Get(root[b[x]-1][1],root[e[x]][1],0,n,0,sz);
	//printf("%i ",ans);
	ans^=Get(root[b[x]-1][0],root[e[x]][0],0,n,0,sz);
	return ans;
}
int main()
{
	int q,i,u,v,x;
	scanf("%i %i",&n,&q);
	for(u=2;u<=n;u++)
	{
		scanf("%i",&v);
		Tree[v].push_back(u);
		Tree[u].push_back(v);
	}
	DFS(1,0);
	Set();
	while(q--)
	{
		scanf("%i",&x);
		printf("%i\n",Query(x));
	}
	return 0;
}