#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

bool T[1001][1001];

int main()
{
	//ios_base::sync_with_stdio(0);
	int n, k;
	scanf("%d%d", &n, &k);
	if(k>(n-1)/2)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", n*k);
	for(int i=1; i<=n; i++)
	{
		int li=0;
		for(int j=1; j<=n; j++)
		{
			if(li==k) break;
			if(i==j) continue;
			if(!T[i][j] && !T[j][i]) {T[i][j]=1; li++;}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(T[i][j]) printf("%d %d\n", i, j);
		}
	}
	return 0;
}