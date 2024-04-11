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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = (int)1e6 + 7;
int n, m;
char s[N];
bool used[N];
char ans[N];

void solve() {
	scanf("%s", s);
	n = strlen(s);
	m = 0;
	int p = -1;
	for (int i = 0; i < n; i++)
		used[i] = 0;
	for (char c = '0'; c <= '9'; c++) {
		for (int i = 0; i < p; i++) if (!used[i] && s[i] + 1 == c) {
			used[i] = 1;
			ans[m++] = c;
		}
		for (int i = p + 1; i < n; i++) {
			if (used[i] || s[i] != c) continue;
			used[i] = 1;
			ans[m++] = s[i];
			p = i;
		}
	}
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			assert(s[i] == '9');
			ans[m++] = '9';
		}
	ans[m] = '\0';
	assert(m == n);
	printf("%s\n", ans);
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