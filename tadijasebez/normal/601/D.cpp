#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define pb push_back
const int N=300050;
vector<int> E[N];
int go[N][26],tsz,root,lid[N],rid[N],id[N],isz,sol[N];
char ch[N];
set<int> Set[N];
void DFS(int u, int p, int &c)
{
	if(!c) c=++tsz;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u,go[c][ch[v]-'a']);
	}
}
void Solve(int u, int p, int c)
{
	int i;
	set<int>::iterator it;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) Solve(v,u,go[c][ch[v]-'a']);
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && Set[id[v]].size()>Set[id[u]].size()) id[u]=id[v];
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && id[v]!=id[u])
		{
			for(it=Set[id[v]].begin();it!=Set[id[v]].end();it++) Set[id[u]].insert(*it);
		}
	}
	if(!id[u]) id[u]=++isz;
	Set[id[u]].insert(c);
	sol[u]+=Set[id[u]].size();
}
int main()
{
	root=++tsz;
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&sol[i]);
	scanf("%s",ch+1);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0,go[root][ch[1]-'a']);
	Solve(1,0,go[root][ch[1]-'a']);
	int ans=0,cnt=0;
	for(i=1;i<=n;i++)
	{
		if(sol[i]>ans) ans=sol[i],cnt=0;
		if(sol[i]==ans) cnt++;
	}
	printf("%i\n%i\n",ans,cnt);
	//for(i=1;i<=n;i++) printf("%i ",sol[i]);printf("\n");
	return 0;
}