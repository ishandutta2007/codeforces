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

int n, d, h;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &n, &d, &h);
	if(n==2)
	{
		printf("1 2\n");
		return 0;
	}
	if(d<2 || (d+1)/2>h)
	{
		printf("-1\n");
		return 0;
	}
	if(d==h)
	{
		for(int i=2; i<=d+1; i++)
			printf("%d %d\n", i-1, i);
		for(int i=d+2; i<=n; i++)
			printf("%d %d\n", i, 2);
		return 0;
	}
	for(int i=2; i<=h+1; i++)
		printf("%d %d\n", i-1, i);
	printf("%d 1\n", h+2);
	for(int i=h+3; i<=d+1; i++)
		printf("%d %d\n", i-1, i);
	for(int i=d+2; i<=n; i++)
		printf("%d 1\n", i);
	return 0;
}