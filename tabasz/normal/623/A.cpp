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

int n, m, A[505], x, y;
bool T[505][505];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n ,&m);
	if(m==n*(n-1)/2)
	{
		printf("Yes\n");
		for(int i=1; i<=n; i++)
			printf("a");
		printf("\n");
		return 0;
	}
	for(int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		T[a][b]=1;
		T[b][a]=1;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if(!T[i][j])
			{
				A[i]=1;
				A[j]=3;
				x=i;
				y=j;
				break;
			}
		}
		if(x!=0)
			break;
	}
	for(int i=1; i<=n; i++)
	{
		if(i!=x && i!=y)
		{
			if(T[x][i] && T[y][i])
				A[i]=2;
			if(T[x][i] && !T[y][i])
				A[i]=1;
			if(!T[x][i] && T[y][i])
				A[i]=3;
			if(!T[x][i] && !T[y][i])
			{
				printf("No\n");
				return 0;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if(T[i][j] && abs(A[j]-A[i])>1)
			{
				printf("No\n");
				return 0;
			}
			if(!T[i][j] && abs(A[j]-A[i])<2)
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	for(int i=1; i<=n; i++)
		printf("%c", (char)((int)'a'+A[i]-1));
	printf("\n");
	return 0;
}