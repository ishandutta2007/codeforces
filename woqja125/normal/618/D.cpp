#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
std::vector<int> map[200001];
int X, Y;
long long num[200001][2];
void dfs(int x, int p)
{
	int min=10000000, min2=10000000;
	int sum = 0, d=0;
	for(int xx: map[x])
	{
		if(xx == p) continue;
		dfs(xx, x);
		d++;
		int di = num[xx][1] - num[xx][0];
		if(di < min)
		{
			min2 = min;
			min = di;
		}
		else if(di < min2)
		{
			min2 = di;
		}
		sum += num[xx][0];
	}
	if(d==0) return;
	if(d==1) num[x][1] = num[x][0] = sum+min;
	else
	{
		num[x][1] = sum+min+(d-1);
		num[x][0] = sum+min+min2+d-2;
	}
}
int main()
{
	int n, i, a, b;
	scanf("%d%d%d", &n, &X, &Y);
	for(i=1; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	if(n==2)
	{
		printf("%d", X);
		return 0;
	}
	int r;
	for(r=1; r<=n && map[r].size() == 1; r++);
	if(X<=Y)
	{
		dfs(r, -1);
		printf("%lld", 1ll*num[r][0]*Y+1ll*(n-num[r][0]-1)*X);
	}
	else
	{
		if(map[r].size() == n-1) printf("%lld", (n-2ll)*Y+X);
		else printf("%lld", (n-1ll)*Y);
	}
	return 0;
}