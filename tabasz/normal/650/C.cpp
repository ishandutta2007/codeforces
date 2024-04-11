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

int T[1000005], n, m, R[1000005], in[1000005];
vector<PII> A[1000005];
vector<int> V[1000005];
queue<int> Q;

int find(int a)
{
	if(T[a]==a)
		return a;
	return T[a]=find(T[a]);
}

void onion(int a, int b)
{
	T[find(b)]=find(a);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n*m; i++)
		T[i]=i;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int a;
			scanf("%d", &a);
			A[i].PB(MP(a, i*m+j));
			A[n+j].PB(MP(a, i*m+j));
		}
	}
	for(int i=0; i<n+m; i++)
		sort(A[i].begin(), A[i].end());
	for(int i=0; i<n+m; i++)
		for(int j=1; j<(int)A[i].size(); j++)
			if(A[i][j].F==A[i][j-1].F)
				onion(A[i][j].S, A[i][j-1].S);
	for(int i=0; i<n+m; i++)
	{
		for(int j=1; j<(int)A[i].size(); j++)
		{
			if(A[i][j].F>A[i][j-1].F)
			{
				//printf("%d %d\n", A[i][j-1].S, A[i][j].S);
				V[find(A[i][j-1].S)].PB(find(A[i][j].S));
				in[find(A[i][j].S)]++;
			}
		}
	}
	for(int i=0; i<n*m; i++)
	{
		if(find(i)==i && in[i]==0)
		{
			Q.push(i);
			R[i]=1;
		}
	}
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		for(int i=0; i<(int)V[v].size(); i++)
		{
			in[V[v][i]]--;
			R[V[v][i]]=max(R[V[v][i]], R[v]+1);
			if(in[V[v][i]]==0)
				Q.push(V[v][i]);
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%d ", R[find(i*m+j)]);
		printf("\n");
	}
	return 0;
}