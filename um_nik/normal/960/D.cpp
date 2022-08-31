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

const int K = 62;
ll a[K], b[K];

int getLevel(ll x) {
	int p = 0;
	while(x + 1 > (1LL << p)) p++;
	p--;
	return p;
}

ll getVertexById(ll x, int p) {
	x -= 1LL << p;
	x += a[p];
	x %= 1LL << p;
	if (x < 0) x += 1LL << p;
	return x + (1LL << p);
}
ll getIdByVertex(ll x, int p) {
	x -= 1LL << p;
	x -= a[p];
	x %= 1LL << p;
	if (x < 0) x += 1LL << p;
	return x + (1LL << p);
}
ll getParent(ll v, int p) {
	v -= 1LL << p;
	v += b[p];
	v %= 1LL << p;
	if (v < 0) v += 1LL << p;
	v /= 2;
	v += 1LL << (p - 1);
	return v;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	while(q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			ll x, k;
			scanf("%lld%lld", &x, &k);
			int p = getLevel(x);
			a[p] += k;
			a[p] %= (1LL << p);
			if (a[p] < 0)
				a[p] += 1LL << p;
		} else if (t == 2) {
			ll x, k;
			scanf("%lld%lld", &x, &k);
			int p = getLevel(x);
			b[p] += k;
			b[p] %= (1LL << p);
			if (b[p] < 0)
				b[p] += 1LL << p;
		} else {
			ll x;
			scanf("%lld", &x);
			int p = getLevel(x);
			ll v = getVertexById(x, p);
			while(v > 1) {
				printf("%lld ", getIdByVertex(v, p));
				v = getParent(v, p);
				p--;
			}
			printf("1\n");
		}
	}

	return 0;
}