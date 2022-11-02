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

int n;
vector<int> A[1005][1005];
PII T[1000005];

bool cmp1(int a, int b)
{
	if(T[a].S==T[b].S)
		return T[a].F<T[b].F;
	return T[a].S<T[b].S;
}

bool cmp2(int a, int b)
{
	if(T[a].S==T[b].S)
		return T[a].F<T[b].F;
	return T[a].S>T[b].S;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		T[i+1]=MP(a, b);
		A[a/1000][b/1000].PB(i+1);
	}
	for(int i=0; i<=1000; i++)
	{
		for(int j=0; j<=1000; j++)
		{
			if(i%2==0)
				sort(A[i][j].begin(), A[i][j].end(), cmp1);
			else
				sort(A[i][j].begin(), A[i][j].end(), cmp2);
		}
	}
	for(int i=0; i<=1000; i++)
	{
		if(i%2==0)
		{
			for(int j=0; j<=1000; j++)
			{
				for(int k=0; k<(int)A[i][j].size(); k++)
					printf("%d ", A[i][j][k]);
			}
		}
		else
		{
			for(int j=1000; j>=0; j--)
			{
				for(int k=(int)A[i][j].size()-1; k>=0; k--)
					printf("%d ", A[i][j][k]);
			}
		}
	}
	printf("\n");
	return 0;
}