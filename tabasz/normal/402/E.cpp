#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long

bool vis[2002];
vector<int> V[2002], V2[2002];
int T[2002];
pair<int, int> P[2002];
int p=0;

void DFS(int v)
{
	vis[v]=1;
	for(int i=0; i<V[v].size(); i++) if(!vis[V[v][i]]) DFS(V[v][i]);
	P[v]=MP(p, v);
	p++;
	return;
}

void DFS2(int v, int sp)
{
	vis[v]=1;
	T[v]=sp;
	for(int i=0; i<V2[v].size(); i++) if(!vis[V2[v][i]]) DFS2(V2[v][i], sp);
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int a;
			scanf("%d", &a);
			if(a!=0 && i!=j)
			{
				V[i].PB(j);
				V2[j].PB(i);
			}
		}
	}
	for(int i=0; i<n; i++) if(!vis[i]) DFS(i);
	for(int i=0; i<n; i++) vis[i]=0;
	sort(P, P+n);
	for(int i=n-1; i>=0; i--) if(!vis[P[i].S]) DFS2(P[i].S, P[i].S);
	bool b=1;
	int p=T[0];
	for(int i=1; i<n; i++)
	{
		if(p!=T[i])
		{
			b=0;
			break;
		}
	}
	if(b) printf("YES\n");
	else printf("NO\n");
	return 0;
}