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

int n;
vector<int> V[200005];
int S[200005], T[2][200005];//mini, maxi

void DFS(int v, int depth)
{
	if(V[v].size()==0)
	{
		S[v]=1;
		T[0][v]=1;
		T[1][v]=1;
		return;
	}
	for(int i=0; i<(int)V[v].size(); i++)
	{
		DFS(V[v][i], depth+1);
		S[v]+=S[V[v][i]];
	}
	if(depth%2)
	{
		int tmp=1000000000;
		for(int i=0; i<(int)V[v].size(); i++)
		{
			tmp=min(tmp, T[0][V[v][i]]);
			T[1][v]+=T[1][V[v][i]]-1;
		}
		T[0][v]=tmp;
		T[1][v]++;
	}
	else
	{
		for(int i=0; i<(int)V[v].size(); i++)
		{
			T[1][v]=max(T[1][v], S[v]-S[V[v][i]]+T[1][V[v][i]]);
			T[0][v]+=T[0][V[v][i]];
		}
	}
}

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
	}
	DFS(1, 0);
	printf("%d %d\n", T[1][1], T[0][1]);
	return 0;
}