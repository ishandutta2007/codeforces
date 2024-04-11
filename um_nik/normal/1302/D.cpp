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

const int N = 100100;
int n;
char s[N];
const int A = 26;
int a[A];
ll b[A][A];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < A; j++)
			b[j][(int)(s[i] - 'a')] += a[j];
		a[(int)(s[i] - 'a')]++;
	}
	ll ans = 0;
	for (int i = 0; i < A; i++) {
		ans = max(ans, (ll)a[i]);
		for (int j = 0; j < A; j++)
			ans = max(ans, b[i][j]);
	}
	printf("%lld\n", ans);

	return 0;
}