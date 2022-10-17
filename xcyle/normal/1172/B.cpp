#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 200005
#define ll long long
using namespace std;
const int mo = 998244353;
int n, a, b, ans, d[maxn], fac[maxn];
int main()
{
	scanf("%d", &n);
	fac[0] = 1;
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		d[a]++;
		d[b]++;
		fac[i] = (ll)fac[i - 1] * i % mo; 
	}
	int ans = n;
	for (int i = 1; i <= n; i++)
	{
		ans = (ll)ans * fac[d[i]] % mo;
	}
	printf("%d", ans);
	return 0;
}