#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int n, m, l=1000000000;
vector<PII> V[100005];
vector<int> R, R2, A[100005][10];
bool B[100005];
int dist[100005], F[100005], dist2[100005];
PII pref[100005];
queue<int> Q;

void BFS2(int v)
{
	Q.push(v);
	B[v]=1;
	pref[v]=MP(-1, 0);
	for(int i=0; i<n-1; i++)
		dist2[v]=1000000000;
	while(!Q.empty())
	{
		int a=Q.front();
		Q.pop();
		for(int i=0; i<(int)V[a].size(); i++)
		{
			if(V[a][i].S==0 && !B[V[a][i].F])
			{
				B[V[a][i].F]=1;
				dist2[V[a][i].F]=dist2[a]+1;
				pref[V[a][i].F]=MP(a, 0);
				Q.push(V[a][i].F);
			}
		}
	}
}

void BFS()
{
	for(int i=1; i<n; i++)
		dist[i]=1000000000;
	Q.push(0);
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		if(B[v])
			l=min(l, dist[v]);
		for(int i=0; i<(int)V[v].size(); i++)
		{
			if(dist[V[v][i].F]==1000000000)
			{
				dist[V[v][i].F]=dist[v]+1;
				if(B[V[v][i].F])
					l=min(l, dist[V[v][i].F]);
				Q.push(V[v][i].F);
			}
		}
	}
}

void getpath()
{
	int v=0;
	while(v!=-1)
	{
		R2.PB(v);
		v=pref[v].F;
	}
}

bool cmp(int a, int b)
{
	return dist2[a]<dist2[b];
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		V[a].PB(MP(b, c));
		V[b].PB(MP(a, c));
	}
	for(int i=0; i<n; i++)
		pref[i]=MP(-1, 1000);
	BFS2(n-1);
	BFS();
	for(int i=0; i<n; i++)
		if(B[i] && dist[i]==l)
			A[l][0].PB(i);
	F[l]=0;
	sort(A[l][0].begin(), A[l][0].end(), cmp);
	for(int i=l; i>0; i--)
	{
		F[i-1]=10;
		for(int j=0; j<(int)A[i][F[i]].size(); j++)
		{
			int v=A[i][F[i]][j];
			for(int k=0; k<(int)V[v].size(); k++)
			{
				if(dist[V[v][k].F]==dist[v]-1 && pref[V[v][k].F].S>V[v][k].S)
				{
					F[i-1]=min(F[i-1], V[v][k].S);
					A[dist[v]-1][V[v][k].S].PB(V[v][k].F);
					pref[V[v][k].F]=MP(v, V[v][k].S);
				}
			}
		}
		R.PB(F[i-1]);
	}
	for(int i=0; i<(int)R.size(); i++)
		printf("%d", R[i]);
	if((int)R.size()==0)
		printf("0");
	printf("\n");
	getpath();
	printf("%d\n", (int)R2.size());
	for(int i=0; i<(int)R2.size(); i++)
		printf("%d ", R2[i]);
	printf("\n");
	return 0;
}