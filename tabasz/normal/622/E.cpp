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

int n, res=0;
vector<int> V[500005], A[500005];

void DFS(int v, int prev, int ind, int d)
{
	if(V[v].size()==1)
		A[ind].PB(d);
	for(int i=0; i<(int)V[v].size(); i++)
		if(V[v][i]!=prev)
			DFS(V[v][i], v, ind, d+1);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int i=0; i<(int)V[1].size(); i++)
		DFS(V[1][i], 1, V[1][i], 1);
	for(int i=2; i<=n; i++)
	{
		int tmp=0;
		sort(A[i].begin(), A[i].end());
		for(int j=0; j<(int)A[i].size(); j++)
		{
			if(A[i][j]>tmp)
				tmp=A[i][j];
			else
				tmp++;
		}
		res=max(res, tmp);
	}
	printf("%d\n", res);
	return 0;
}