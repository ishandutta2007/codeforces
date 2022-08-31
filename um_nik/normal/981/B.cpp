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

map<int, ll> a;
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int k = 0; k < 2; k++) {
		scanf("%d", &n);
		while(n--) {
			int x;
			ll y;
			scanf("%d%lld", &x, &y);
			a[x] = max(a[x], y);
		}
	}
	ll ans = 0;
	for (auto t : a)
		ans += t.second;
	printf("%lld\n", ans);

	return 0;
}