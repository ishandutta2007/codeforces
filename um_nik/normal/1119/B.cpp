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
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;
int n;
ll h;
ll a[N];
ll b[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &h);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	int l = 0, r = n + 1;
	while(r - l > 1) {
		int x = (l + r) / 2;
		for (int i = 0; i < x; i++)
			b[i] = a[i];
		sort(b, b + x);
		b[x] = 0;
		ll cur = h;
		for (int i = x - 1; i >= 0; i -= 2)
			cur -= b[i];
		if (cur >= 0)
			l = x;
		else
			r = x;
	}
	printf("%d\n", l);

	return 0;
}