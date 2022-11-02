#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, m, a, b, pr[600005], prew[600005], tmpp, X[600006], S[600006];
vector<int> V[600005];
bool vis[600006], GS[600006];

void DFS(int v, int pre)
{
	vis[v]=1;
	prew[v]=pre;
	pr[v]=tmpp;
	tmpp++;
	X[v]=pr[v];
	for(int i=0; i<(int)V[v].size(); i++)
		if(vis[V[v][i]] && V[v][i]!=prew[v])
			X[v]=min(X[v], pr[V[v][i]]);
	for(int i=0; i<(int)V[v].size(); i++)
		if(!vis[V[v][i]])
			DFS(V[v][i], v);
	for(int i=0; i<(int)V[v].size(); i++)
		if(prew[V[v][i]]==v)
			X[v]=min(X[v], X[V[v][i]]);
}

void DFS2(int v, int x)
{
	vis[v]=0;
	if(X[v]==pr[v])
		x=v;
	S[v]=x;
	for(int i=0; i<(int)V[v].size(); i++)
		if(vis[V[v][i]])
			DFS2(V[v][i], x);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	int tmp=n+1;
	for(int i=1; i<=m; i++)
	{
		int aa, bb, c;
		scanf("%d%d%d", &aa, &bb, &c);
		if(c)
		{
			V[aa].PB(tmp);
			V[tmp].PB(aa);
			V[tmp].PB(bb);
			V[bb].PB(tmp);
			tmp++;
		}
		else
		{
			V[aa].PB(bb);
			V[bb].PB(aa);
		}
	}
	scanf("%d%d", &a, &b);
	DFS(a, 0);
	DFS2(a, a);
	int v=b;
	while(v!=0)
	{
		GS[S[v]]=1;
		v=prew[v];
	}
	for(int i=n+1; i<tmp; i++)
	{
		if(GS[S[i]])
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}