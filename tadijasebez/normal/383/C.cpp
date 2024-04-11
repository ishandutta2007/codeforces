#include <stdio.h>
#include <vector>
using namespace std;
const int M=1000000;
const int N=200050;
int x[M],ls[M],rs[M],clock,root[2];
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(!c) c=++clock;
	if(qs>se || ss>qe) return;
	if(qs<=ss && se<=qe)
	{
		x[c]+=val;
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
int ans;
void Get(int c, int ss, int se, int qi)
{
	ans+=x[c];
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Get(ls[c],ss,mid,qi);
	else Get(rs[c],mid+1,se,qi);
}
vector<int> Tree[N];
int b[N],e[N],time;
int a[N],Depth[N];
void DFS(int cur, int prev, int depth)
{
	int i;
	Depth[cur]=depth;
	b[cur]=++time;
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
int main()
{
	int n,q,i,u,v,t,w;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	DFS(1,0,1);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&u,&w);
			Set(root[Depth[u]&1],1,n,b[u],e[u],w);
			Set(root[1-Depth[u]&1],1,n,b[u],e[u],-w);
		}
		else
		{
			scanf("%i",&u);
			ans=a[u];
			Get(root[Depth[u]&1],1,n,b[u]);
			printf("%i\n",ans);
		}
	}
	return 0;
}