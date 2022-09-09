#include <stdio.h>
#include <vector>
using namespace std;
const int N=500050;
const int M=N*20;
bool x[N][26];
int ls[M],rs[M],ind[M],clock,root[N],leaf;
void Set(int p, int &c, int ss, int se, int qi, char u)
{
	int i;
	c=++clock,ls[c]=ls[p],rs[c]=rs[p];
	if(ss==se)
	{
		ind[c]=++leaf;
		for(i=0;i<26;i++) x[ind[c]][i]=x[ind[p]][i];
		x[ind[c]][u-'a']^=1;
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,u);
	else Set(rs[p],rs[c],mid+1,se,qi,u);
}
bool ans[26];
void Get(int p, int c, int ss, int se, int qs, int qe)
{
	int i;
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		for(i=0;i<26;i++) ans[i]^=x[ind[p]][i]^x[ind[c]][i];
		return;
	}
	int mid=ss+se>>1;
	Get(ls[p],ls[c],ss,mid,qs,qe);
	Get(rs[p],rs[c],mid+1,se,qs,qe);
}
vector<int> Tree[N];
int Depth[N],Node[N],b[N],e[N],time;
void DFS(int cur, int prev, int depth)
{
	Depth[cur]=depth;
	b[cur]=++time;
	Node[b[cur]]=cur;
	int i;
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
char a[N];
void Set(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		Set(root[i-1],root[i],1,n,Depth[Node[i]],a[Node[i]-1]);
	}
}
int main()
{
	int n,i,u,v,q,d;
	scanf("%i %i",&n,&q);
	for(i=2;i<=n;i++) scanf("%i",&u),Tree[u].push_back(i);
	scanf("%s",&a);
	DFS(1,0,1);
	Set(n);
	while(q--)
	{
		scanf("%i %i",&u,&d);
		for(i=0;i<26;i++) ans[i]=0;
		Get(root[b[u]-1],root[e[u]],1,n,d,d);
		int sum=0;
		for(i=0;i<26;i++) sum+=ans[i];
		if(sum<2) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}