#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	scanf("%lld", &n);
	ll ans = 0;
	for(int i = 1; (1ll << i) <= 3e12; i++)
		ans += ((n >> i) + ll((n & ((1ll << i) - 1ll)) > (1ll << (i - 1)))) * (1ll << (i - 1));
	printf("%lld\n", ans);
}