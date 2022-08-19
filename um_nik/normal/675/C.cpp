#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

typedef long long ll;
map<ll, int> a;
int ans = 0;
int n;


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	ll bal = 0;
	for (int i = 0; i < n; i++)
	{
		ll x;
		scanf("%lld", &x);
		bal += x;
		a[bal]++;
		ans = max(ans, a[bal]);
	}
	printf("%d\n", n - ans);

	return 0;
}