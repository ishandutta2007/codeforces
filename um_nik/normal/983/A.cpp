#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		ll p, q, b;
		scanf("%lld%lld%lld", &p, &q, &b);
		ll g = gcd(p, q);
		q /= g;
		while(true) {
			b = gcd(q, b);
			if (b == 1) break;
			q /= b;
		}
		if (q == 1)
			printf("Finite\n");
		else
			printf("Infinite\n");
	}

	return 0;
}