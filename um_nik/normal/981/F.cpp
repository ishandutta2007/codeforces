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

const int N = (int)1e6;
ll a[N];
ll b[N];
int c[N], d[N];
int n;

bool solve(ll D) {
	int l = 0, r = 0;
	for (int i = 0; i < 2 * n; i++) {
		while(a[r] <= b[i] + D) r++;
		while(a[l] < b[i] - D) l++;
		c[i] = l;
		d[i] = r - 1;
	}
	int mx = -3 * N;
	for (int i = 0; i < 2 * n; i++) {
		mx = max(mx, c[i] - i);
		if (mx + i - d[i] > 0)
			return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll L;
	scanf("%d%lld", &n, &L);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	sort(b, b + n);
	for (int i = 0; i < 3 * n; i++)
		a[i + n] = a[i] + L;
	for (int i = 0; i < n; i++) {
		b[i] += L;
		b[i + n] = b[i] + L;
	}
	ll l = -1, r = L;
	while(r - l > 1) {
		ll x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	printf("%lld\n", r);

	return 0;
}