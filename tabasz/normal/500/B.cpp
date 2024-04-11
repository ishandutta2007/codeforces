#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

vector<int> V[303];
bool vis[303];
int T[303], R[303];
vector<int> W[2];

void DFS(int v)
{
	vis[v]=1;
	W[0].PB(T[v]);
	W[1].PB(v);
	for(int i=0; i<(int)V[v].size(); i++) if(!vis[V[v][i]]) DFS(V[v][i]);
}

int main()
{
	int n;
	char x;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", T+i);
	scanf("%c", &x);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%c", &x);
			if(x=='1')
			{
				V[i].PB(j);
				V[j].PB(i);
			}
		}
		scanf("%c", &x);
	}
	for(int i=1; i<=n; i++)
	{
		if(!vis[i]) DFS(i);
		sort(W[0].begin(), W[0].end());
		sort(W[1].begin(), W[1].end());
		for(int j=0; j<(int)W[0].size(); j++)
		{
			R[W[1][j]]=W[0][j];
		}
		W[0].clear();
		W[1].clear();
	}
	for(int i=1; i<=n; i++) printf("%d ", R[i]);
	printf("\n");
	return 0;
}