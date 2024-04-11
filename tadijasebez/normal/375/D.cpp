#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e5+50;
int root=1;
struct Query
{
	int b,e,c,i;
	Query(){}
	Query(int j, int k, int l, int m)
	{
		b=j;
		e=k;
		c=l;
		i=m;
	}
	inline bool operator < (const Query &x) const
	{
		if(e/root==x.e/root) return b<x.b;
		return e/root<x.e/root;
	}
};
vector<Query> Q;
int C[N],Sol[N],Cnt[N],ans[N],b[N],e[N],time,Node[N];
vector<int> Tree[N];
void DFS(int cur, int prev)
{
	b[cur]=++time;
	Node[time]=cur;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev) DFS(v,cur);
	}
	e[cur]=time;
}
int main()
{
	int n,q,u,v,i;
	scanf("%i %i",&n,&q);
	root=sqrt(n);
	for(i=1;i<=n;i++) scanf("%i",&C[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	DFS(1,0);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&u,&v);
		Q.push_back(Query(b[u],e[u],v,i));
	}
	sort(Q.begin(),Q.end());
	int l=1,r=0;
	for(i=0;i<Q.size();i++)
	{
		while(r<Q[i].e) Sol[++Cnt[C[Node[++r]]]]++;
		while(r>Q[i].e) Sol[Cnt[C[Node[r--]]]--]--;
		while(l<Q[i].b) Sol[Cnt[C[Node[l++]]]--]--;
		while(l>Q[i].b) Sol[++Cnt[C[Node[--l]]]]++;
		ans[Q[i].i]=Sol[Q[i].c];
	}
	for(i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}