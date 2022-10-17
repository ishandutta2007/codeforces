#include <iostream>
#include <cstdio>
#define maxn 600005
using namespace std;
int n, b[maxn];
long long t[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		t[b[i] - i + n] += b[i];
	}
	long long ans = 0;
	for (int i = 0; i < maxn; i++)
	{
		ans = max(ans, t[i]);
	}
	printf("%lld", ans);
	return 0;
}