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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = (int)1e6 + 77;
int n, k;
bool ban[N];
char s[N];
int pref[N];

void solve() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	int m = 0;
	while(m < k && (1 << m) <= n) m++;
	for (int i = 0; i <= n && i < (1 << m); i++)
		ban[i] = false;
	pref[0] = 0;
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + (int)(s[i] == '0');
	for (int l = 0; l + k <= n; l++) {
		if (pref[l] != pref[l + k - m]) continue;
		int mask = 0;
		for (int i = 0; i < m; i++)
			if (s[l + k - 1 - i] == '0')
				mask ^= 1 << i;
		if (mask <= n) ban[mask] = 1;
	}
	int ans = 0;
	while(ans < (1 << m) && ban[ans]) ans++;
	if (ans == (1 << m)) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for (int i = 0; i < k - m; i++)
		printf("0");
	for (int i = m - 1; i >= 0; i--)
		printf("%d", (ans >> i) & 1);
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}