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

map<int, vector<int>> mapchik;

int solve(vector<int> a) {
	sort(all(a));
	vector<bool> used((int)a.size(), false);
	int p = 0;
	int ans = 2 * (int)a.size();
	for (int i = 0; i < (int)a.size(); i++) {
		if (used[i]) continue;
		while(p < (int)a.size() && (used[p] || a[p] < a[i] + 1)) p++;
		if (p < (int)a.size() && a[p] == a[i] + 1) {
			ans -= 2;
			used[i] = used[p] = 1;
		}
	}
	return ans;
}
int solve() {
	mapchik.clear();
	int n, X;
	scanf("%d%d", &n, &X);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int k = 0;
		while(x % X == 0) {
			x /= X;
			k++;
		}
		mapchik[x].push_back(k);
	}
	int ans = 0;
	for (auto t : mapchik) ans += solve(t.second);
	return ans - n;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) printf("%d\n", solve());

	return 0;
}