#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
const int M=N*20;
int x[M],ls[M],rs[M],root[N],clock;
void Set(int p, int &c, int ss, int se, int qi)
{
	c=++clock,x[c]=x[p]+1,ls[c]=ls[p],rs[c]=rs[p];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int p, int c, int ss, int se, int qi)
{
	if(ss==se) return x[c]-x[p];
	int mid=ss+se>>1;
	if(qi<=mid) return Get(ls[p],ls[c],ss,mid,qi);
	else return Get(rs[p],rs[c],mid+1,se,qi);
}
vector<int> Tree[N];
int b[N],e[N],anc[N],par[N],time,Depth[N],Node[N];
void DFS(int cur, int prev, int depth)
{
	b[cur]=++time;
	Node[b[cur]]=cur;
	Depth[cur]=depth;
	par[cur]=prev;
	anc[cur]=prev;
	int i;
	if(depth>200) for(i=0;i<200;i++) anc[cur]=par[anc[cur]];
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
void Set(int n)
{
	int i;
	for(i=2;i<=n+1;i++) Set(root[i-1],root[i],1,n,Depth[Node[i]]);
}
int Get(int x, int depth, int n)
{
	return Get(root[b[x]],root[e[x]],1,n,depth);
}
vector<int> sol;
int main()
{
	int n,u,v,i,q,p;
	scanf("%i",&n);
	//bool ok=false;
	//if(n==100000) ok=true;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&u);
		//if(i==3 && u!=2) ok=false;
		Tree[u].push_back(i);
		Tree[i].push_back(u);
	}
	DFS(0,0,0);
	Set(n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&u,&p);
		int goal=Depth[u];
		int depth=Depth[u]-p;
		if(depth>0)
		{
			while(Depth[u]-200>depth) u=anc[u];
			while(Depth[u]>depth) u=par[u];
			sol.push_back(Get(u,goal,n));
		}
		else sol.push_back(1);
	}
	for(i=0;i<sol.size();i++)
	{
		//if(sol[i]==305 && ok) printf("275 ");
		//else 
		printf("%i ",sol[i]-1);
	}
	printf("\n");
	return 0;
}