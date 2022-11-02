#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
const int M=41;

int T[M][M][M][M], P[M][M][M][M], S[M][M];

int sum(int a, int b, int c, int d)
{
	return S[c][d]-S[c][b-1]-S[a-1][d]+S[a-1][b-1];
}

int main()
{
	int n, m, q;
	char c;
	scanf("%d%d%d%c", &n, &m, &q, &c);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			scanf("%c", &c);
			S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
			if(c=='1') S[i][j]++;
		}
		scanf("%c", &c);
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			for(int k=i; k>0; k--)
			{
				for(int l=j; l>0; l--)
				{
					int x=0;
					if(sum(k, l, i, j)==0) x++;
					if(k<i) x+=T[k+1][l][i][j];
					if(l<j) x+=T[k][l+1][i][j];
					if(k<i && l<j) x-=T[k+1][l+1][i][j];
					T[k][l][i][j]=x;
				}
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			for(int k=i; k<=n; k++)
			{
				for(int l=j; l<=m; l++)
				{
					int x=T[i][j][k][l];
					if(k>i) x+=P[i][j][k-1][l];
					if(l>j) x+=P[i][j][k][l-1];
					if(k>i && l>j) x-=P[i][j][k-1][l-1];
					P[i][j][k][l]=x;
				}
			}
		}
	}
	for(int i=0; i<q; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", P[a][b][c][d]);
	}
	return 0;
}