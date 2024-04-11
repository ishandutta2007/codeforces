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

unordered_map<int, int> maskForPrime;
unordered_map<int, int> g;

int solve(int x) {
	if (g.count(x) > 0) return g[x];
	ll mex = 0;
	for (int k = 1;; k++) {
		int z = x >> k;
		if (z == 0) break;
		int y = (x ^ (z << k)) | z;
		y ^= (y & 1);
		mex |= 1LL << solve(y);
	}
	int k = 0;
	while((mex >> k) & 1) k++;
	g[x] = k;
	return k;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		for (int y = 2; y * y <= x; y++) {
			if (x % y != 0) continue;
			int k = 0;
			while(x % y == 0) {
				x /= y;
				k++;
			}
			if (maskForPrime.count(y) == 0)
				maskForPrime[y] = 0;
			maskForPrime[y] |= 1 << k;
		}
		if (x > 1) {
			if (maskForPrime.count(x) == 0)
				maskForPrime[x] = 0;
			maskForPrime[x] |= 1 << 1;
		}
	}
	g[0] = 0;
	int ans = 0;
	for (pii t : maskForPrime)
		ans ^= solve(t.second);
	if (ans)
		printf("Mojtaba\n");
	else
		printf("Arpa\n");

	return 0;
}