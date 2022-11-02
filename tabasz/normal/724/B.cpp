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

int n, m, T[22][22];

bool good()
{
	for(int i=1; i<=n; i++)
	{
		int tmp=0;
		for(int j=1; j<=m; j++)
			if(T[i][j]!=j)
				tmp++;
		if(tmp>2)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", T[i]+j);
	if(good())
	{
		printf("YES\n");
		return 0;
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=i+1; j<=m; j++)
		{
			for(int k=1; k<=n; k++)
				swap(T[k][i], T[k][j]);
			if(good())
			{
				printf("YES\n");
				return 0;
			}
			for(int k=1; k<=n; k++)
				swap(T[k][i], T[k][j]);
		}
	}
	printf("NO\n");
	return 0;
}