#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long int
#define mp make_pair
#define pb push_back
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=1000050;
int go[N][2],t[N];//0 input, 1 not, 2 and, 3 or, 4 xor
int par[N];
bool val[N],tmp[N];
int DFS(int u)
{
	if(t[u]==0) return u;
	if(t[u]==1)
	{
		int cnt=1;
		while(t[go[u][0]]==1)
		{
			u=go[u][0];
			cnt^=1;
		}
		DFS(go[u][0]);
		if(cnt&1) return u;
		else return go[u][0];
	}
	go[u][0]=DFS(go[u][0]);
	go[u][1]=DFS(go[u][1]);
	return u;
}
int dep[N],sum[N];
void DFS2(int u, int p)
{
	par[u]=p;
	dep[u]=dep[p]+1;
	if(t[u]==0) return;
	if(t[u]==1)
	{
		DFS2(go[u][0],u);
		val[u]=!val[go[u][0]];
		sum[go[u][0]]++;
		return;
	}
	DFS2(go[u][0],u);
	DFS2(go[u][1],u);
	if(t[u]==2)
	{
		val[u]=val[go[u][0]]&val[go[u][1]];
		if(val[u]!=((!val[go[u][0]])&val[go[u][1]])) sum[go[u][0]]++;
		if(val[u]!=((!val[go[u][1]])&val[go[u][0]])) sum[go[u][1]]++;
	}
	else if(t[u]==3)
	{
		val[u]=val[go[u][0]]|val[go[u][1]];
		if(val[u]!=((!val[go[u][0]])|val[go[u][1]])) sum[go[u][0]]++;
		if(val[u]!=((!val[go[u][1]])|val[go[u][0]])) sum[go[u][1]]++;
	}
	else if(t[u]==4)
	{
		val[u]=val[go[u][0]]^val[go[u][1]];
		if(val[u]!=((!val[go[u][0]])^val[go[u][1]])) sum[go[u][0]]++;
		if(val[u]!=((!val[go[u][1]])^val[go[u][0]])) sum[go[u][1]]++;
	}
}
void DFS3(int u, int p)
{
	sum[u]+=sum[p];
	if(go[u][0]) DFS3(go[u][0],u);
	if(go[u][1]) DFS3(go[u][1],u);
}
void Print(int u)
{
	printf("%i ",u);
	if(go[u][0]) Print(go[u][0]);
	if(go[u][1]) Print(go[u][1]);
}
char out[N];
int main()
{
	int n,i,u,v;char ch[10];
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch);
		if(ch[0]=='I')
		{
			t[i]=0;
			scanf("%i",&val[i]);
		}
		else if(ch[0]=='N')
		{
			t[i]=1;
			scanf("%i",&go[i][0]);
		}
		else if(ch[0]=='A')
		{
			t[i]=2;
			scanf("%i %i",&go[i][0],&go[i][1]);
		}
		else if(ch[0]=='O')
		{
			t[i]=3;
			scanf("%i %i",&go[i][0],&go[i][1]);
		}
		else
		{
			t[i]=4;
			scanf("%i %i",&go[i][0],&go[i][1]);
		}
	}
	int root=1;
	root=DFS(root);
	DFS2(root,0);
	DFS3(root,0);
	int sz=0;
	for(i=1;i<=n;i++) tmp[i]=val[i];
	for(i=1;i<=n;i++)
	{
		if(t[i]!=0) continue;
		/*u=i;
		val[i]^=1;
		while(par[u]!=0)
		{
			u=par[u];
			if(t[u]==1) val[u]=!val[go[u][0]];
			else if(t[u]==2) val[u]=val[go[u][0]]&val[go[u][1]];
			else if(t[u]==3) val[u]=val[go[u][0]]|val[go[u][1]];
			else if(t[u]==4) val[u]=val[go[u][0]]^val[go[u][1]];
			if(val[u]==tmp[u]) break;
		}*/
		//printf("%i",val[u]);
		int x=0;
		if(dep[i]==sum[i]+1) x=1;
		out[sz++]='0'+(val[root]^x);
		/*u=i;
		val[i]^=1;
		while(par[u]!=0)
		{
			u=par[u];
			if(val[u]==tmp[u]) break;
			val[u]=tmp[u];
			//if(t[u]==1) val[u]=!val[go[u][0]];
			//if(t[u]==2) val[u]=val[go[u][0]]&val[go[u][1]];
			//if(t[u]==3) val[u]=val[go[u][0]]|val[go[u][1]];
			//if(t[u]==4) val[u]=val[go[u][0]]^val[go[u][1]];
		}*/
	}
	out[sz]=0;
	printf("%s",out);
	//Print(root);
	return 0;
}