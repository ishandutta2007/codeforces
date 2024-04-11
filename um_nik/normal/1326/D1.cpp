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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = (int)2e6 + 77;
int n;
char s[N];
int z[N];
int a[N], b[N];

void solve() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i <= 2 * n; i++)
		z[i] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < 2 * n; i++) {
		if (i < r)
			z[i] = min(r - i, z[l + r - i]);
		z[i] = max(z[i], i & 1);
		while(i + z[i] < 2 * n && i - z[i] >= 2 &&
			s[(i - z[i] - 1) / 2] == s[(i + z[i]) / 2]) z[i] += 2;
		if (i + z[i] > r) {
			l = i - z[i];
			r = i + z[i];
		}
	}

//	for (int i = 0; i <= 2 * n; i++)
//		eprintf("%d ", z[i]);
//	eprintf("\n");

	for (int i = 0; i <= n; i++)
		a[i] = b[i] = 0;
	for (int i = 1; i <= n; i++) {
		a[(i - z[i]) / 2] = max(a[(i - z[i]) / 2], z[i]);
	}
	for (int i = n; i < 2 * n; i++) {
		b[(i + z[i]) / 2] = max(b[(i + z[i]) / 2], z[i]);
	}
	int mx = 0;
	int b1 = 0, b2 = n;
	for (int i = 0; 2 * i <= n; i++) {
		if (2 * i + a[i] > mx) {
			mx = 2 * i + a[i];
			b1 = i + a[i];
			b2 = n - i;
		}
		if (2 * i + b[n - i] > mx) {
			mx = 2 * i + b[n - i];
			b1 = i;
			b2 = n - i - b[n - i];
		}
		if (s[i] != s[n - 1 - i]) break;
	}
//	printf("%d %d %d\n", mx, b1, b2);
	int sz = b1;
	for (int i = b2; i < n; i++)
		s[sz++] = s[i];
	s[sz] = '\0';
	printf("%s\n", s);
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}