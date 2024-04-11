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
bool T[101][101];
int A[101][101];
char c;
vector<PII> V;

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d%c", &n, &c);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%c", &c);
			if(c=='o')
			{
				V.PB(MP(i, j));
				A[i][j]=2;
			}
			if(c=='x') A[i][j]=1;
		}
		scanf("%c", &c);
	}
	for(int i=0; i<(int)V.size(); i++)
	{
		for(int j=V[i].F-n+1; j<V[i].F+n; j++)
		{
			for(int k=V[i].S-n+1; k<V[i].S+n; k++)
			{
				if(j>0 && j<=n && k>0 && k<=n)
				{
					if(A[j][k]==0) T[j-V[i].F+n][k-V[i].S+n]=1;
				}
			}
		}
	}
	for(int i=0; i<(int)V.size(); i++)
	{
		for(int j=1; j<2*n; j++)
		{
			for(int k=1; k<2*n; k++)
			{
				int aa=V[i].F+j-n, bb=V[i].S+k-n;
				if(T[j][k]==0 && aa>0 && aa<=n && bb>0 && bb<=n) A[aa][bb]=0;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(A[i][j]==1)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i=1; i<2*n; i++)
	{
		for(int j=1; j<2*n; j++)
		{
			if(i==n && j==n) printf("o");
			else
			{
				if(T[i][j]==1) printf(".");
				else printf("x");
			}
		}
		printf("\n");
	}
	return 0;
}