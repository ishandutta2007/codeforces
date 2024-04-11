#include <bits/stdc++.h>

using namespace std;

int n, a[100005];

const int MOD = 10007;

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	int res = 0;
	for(int i=1; i<=n; i++)
	{
		res = (res + (a[i]*1ll*a[n-i+1]) % MOD) % MOD;
	}
	printf("%d\n", res);
	return 0;
}