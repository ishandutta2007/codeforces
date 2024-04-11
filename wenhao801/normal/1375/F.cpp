#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

const ll inf = 1e10;
ll a[4];
int main () {
	for (int i = 1; i <= 3; i++) scanf("%lld", &a[i]);
	puts("First"); fflush(stdout);
	printf("%lld\n", inf); fflush(stdout);
	int pos; scanf("%d", &pos); a[pos] += inf;
	ll p = a[1], q = a[2], r = a[3];
	if (p > q) swap(p, q); if (p > r) swap(p, r); if (q > r) swap(q, r);
	printf("%lld\n", q - p + 2ll * (r - q)); fflush(stdout);
	int pos2; scanf("%d", &pos2);
	if (a[pos2] == p) printf("%lld\n", r - q); else printf("%lld\n", q - p + r - q);
	fflush(stdout);
	return 0;
}