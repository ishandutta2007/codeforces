#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=200050;
const int M=1<<20;
vector<int> E[N];
int a[N],sz[N];
bool vis[N];
void DFS(int u, int p, int &n)
{
	n++;sz[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v] && v!=p) DFS(v,u,n),sz[u]+=sz[v];
	}
}
int Find(int u, int p, int n)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v] && v!=p && sz[v]>n/2) return Find(v,u,n);
	}
	return u;
}
int Find(int u){ int n=0;DFS(u,u,n);return Find(u,u,n);}
int cnt[M];
ll sol[N],cry[N];
vector<int> lzy,bck;
void Solve(int u, int p, int Xor)
{
	Xor^=a[u];
	bck.push_back(Xor);
	lzy.push_back(Xor);
	cry[u]=cnt[Xor];
	int i;
	for(i=0;i<20;i++) cry[u]+=cnt[Xor^(1<<i)];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && !vis[v]) Solve(v,u,Xor),cry[u]+=cry[v];
	}
	sol[u]+=cry[u];
}
void Decompose(int u)
{
	u=Find(u);vis[u]=1;
	sol[u]++;
	int i,j;
	cnt[0]=1;
	lzy.push_back(a[u]);
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v])
		{
			Solve(v,u,a[u]);
			sol[u]+=cry[v];
			for(j=0;j<bck.size();j++) cnt[bck[j]^a[u]]++;
			bck.clear();
		}
	}
	for(i=0;i<lzy.size();i++) cnt[lzy[i]^a[u]]=0;
	lzy.clear();
	for(i=E[u].size()-1;~i;i--)
	{
		int v=E[u][i];
		if(!vis[v])
		{
			Solve(v,u,a[u]);
			for(j=0;j<bck.size();j++) cnt[bck[j]^a[u]]++;
			bck.clear();
		}
	}
	for(i=0;i<lzy.size();i++) cnt[lzy[i]^a[u]]=0;
	lzy.clear();
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) Decompose(v);
	}
}
char ch[N];
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	scanf("%s",ch+1);
	for(i=1;i<=n;i++) a[i]=1<<(ch[i]-'a');
	Decompose(1);
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);printf("\n");
	return 0;
}