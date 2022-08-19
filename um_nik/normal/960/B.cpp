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

const int N = 1010;
int n, m;
ll a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int k;
	scanf("%d%d%d", &n, &m, &k);
	m += k;
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[i] -= x;
		a[i] = abs(a[i]);
	}
	while(m--) {
		int p = 0;
		for (int i = 0; i < n; i++)
			if (a[i] > a[p])
				p = i;
		a[p] = abs(a[p] - 1);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += a[i] * a[i];
	printf("%lld\n", ans);

	return 0;
}