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

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i++) {
		int par;
		cin >> par;
		--par;
		g[par].push_back(i);
	}
	string s;
	cin >> s;
	vector<vector<int>> cnt(n, vector<int>(2));
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		cnt[i][(s[i] == 'W' ? 0 : 1)]++;
		for (int j : g[i])
			cnt[i][0] += cnt[j][0], cnt[i][1] += cnt[j][1];
		if (cnt[i][0] == cnt[i][1])
			ans++;
	}
	cout << ans << '\n';
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();

	return 0;
}