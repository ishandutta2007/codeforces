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

const int N = 200200;
char s[N];
int n, k;

void solve() {
	scanf("%d%d", &n, &k);
	k = min(n, k);
	scanf("%s", s);
	vector<int> a, b;
	int cur = 0;
	int len = 0;
	for (int i = 0; i < n; i++) {
		int x = (s[i] == 'W' ? 1 : 0);
		if (x != cur) {
			if (cur == 0) {
				a.push_back(len);
			} else {
				b.push_back(len);
			}
			cur = x;
			len = 0;
		}
		len++;
	}
	if (cur == 0) {
		a.push_back(len);
	} else {
		b.push_back(len);
		a.push_back(0);
	}
	int cntZ = 0;
	for (int x : a) cntZ += x;
	if (cntZ <= k) {
		printf("%d\n", 2 * n - 1);
		return;
	}
	if (b.empty()) {
		printf("%d\n", max(0, 2 * k - 1));
		return;
	}
	int ans = 0;
	for (int x : b) ans += 2 * x - 1;
	a.pop_back();
	reverse(all(a));
	a.pop_back();
	sort(all(a));
	ans += 2 * k;
	for (int x : a) {
		if (x <= k) {
			ans++;
			k -= x;
		} else break;
	}
	printf("%d\n", ans);
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