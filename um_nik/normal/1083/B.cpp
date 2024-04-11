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

const int N = 500500;
int n;
ll k;
ll ans;
char s[N], p[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	if (k == 1) {
		printf("%d\n", n);
		return 0;
	}
	scanf("%s %s", s, p);
	ans = 0;
	ll cur = 1;
	for (int i = 0; i < n; i++) {
		cur *= 2;
		if (s[i] == 'b') cur--;
		if (p[i] == 'a') cur--;
		cur = min(cur, k);
		ans += cur;
	}
	
	printf("%lld\n", ans);

	return 0;
}