#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p = 998244353;
int n;
long long f[Maxn], sum;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			f[j]++;
	for (int i = 1; i <= n; i++)
		(f[i] += sum) %= p, (sum += f[i]) %= p;
	printf("%lld", f[n]);
	return 0;
}