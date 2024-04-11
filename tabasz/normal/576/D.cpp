#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
#include<bitset>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int n, m, res;
vector<pair<int, PII> > E;
bitset<150> B[5][202], R[202], A[2];
int dist[202];
queue<int> Q;

void BFS()
{
	for(int i=1; i<=n; i++)
		dist[i]=1000000000;
	for(int i=1; i<=n; i++)
	{
		if(A[0][i])
		{
			dist[i]=0;
			Q.push(i);
		}
	}
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		for(int i=1; i<=n; i++)
		{
			if(dist[i]==1000000000 && B[0][v][i])
			{
				dist[i]=dist[v]+1;
				Q.push(i);
			}
		}
	}
}

void mno(int ind)
{
	for(int i=1; i<=n; i++)
			B[2][i].reset();
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(R[i][j])
				B[2][i]|=B[ind][j];
	for(int i=1; i<=n; i++)
			R[i]=B[2][i];
}


void mnoz(int a)
{
	//printf("asd %d\n", a);
	for(int i=1; i<=n; i++)
			R[i].reset();
	for(int j=1; j<=n; j++)
		R[j][j]=1;
	int i=31;
	/*for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			printf("%d ", B[0][i][j]);
		printf("\n");
	}*/
	while(i>=0)
	{
		if(a>>i==0)
		{
			i--;
			continue;
		}
		for(int k=1; k<=n; k++)
				B[1][k]=R[k];
		mno(1);
		if((a>>i)%2)
			mno(0);
		i--;
	}
	/*for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			printf("%d ", R[i][j]);
		printf("\n");
	}*/
}

void mnoza()
{
	A[1].reset();
	for(int j=1; j<=n; j++)
		if(A[0][j])
			A[1]|=R[j];
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	A[0][1]=1;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E.PB(MP(c, MP(a, b)));
	}
	sort(E.begin(), E.end());
	E.PB(MP(1000001000, MP(1, n)));
	if(E[0].F>0)
	{
		printf("Impossible\n");
		return 0;
	}
	int tmp=0, prev=0;
	B[0][n][n]=1;
	while(E[tmp].F==0)
	{
		B[0][E[tmp].S.F][E[tmp].S.S]=1;
		//printf("%d %d\n", E[tmp].S.F, E[tmp].S.S);
		tmp++;
	}
	while(tmp<=m)
	{
		mnoz(E[tmp].F-E[tmp-1].F);
		mnoza();
	//	printf("qwe %d\n", tmp);
		//for(int i=1; i<=n; i++)
	//		printf("AAA %d\n", A[1][i]);
		if(A[1][n])
		{
			BFS();
			printf("%d\n", res+dist[n]);
			return 0;
		}
		A[0]=A[1];
		res+=E[tmp].F-E[tmp-1].F;
		prev=E[tmp].F;
		while(tmp<=m && E[tmp].F==prev)
		{
			B[0][E[tmp].S.F][E[tmp].S.S]=1;
		//	printf("%d %d\n", E[tmp].S.F, E[tmp].S.S);
			tmp++;
		}
	}
	printf("Impossible\n");
	return 0;
}