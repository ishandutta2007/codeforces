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

int solve(vector<int> box, vector<int> spec) {
	sort(all(box));
	sort(all(spec));
	int n = (int)box.size(), m = (int)spec.size();
	vector<int> onSpec(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int p = lower_bound(all(spec), box[i]) - spec.begin();
		if (p < m && spec[p] == box[i])
			onSpec[i] = 1;
	}
	for (int i = n - 1; i >= 0; i--)
		onSpec[i] += onSpec[i + 1];
	int ans = onSpec[0];
	for (int i = 0; i < n; i++)
		box[i] -= i;
	for (int i = 0; i < m; i++) {
		// 0-th on position spec[i] => p-th on position spec[i] + p >= box[p]
		// spec[i] >= box[p] - p
		int len = upper_bound(all(box), spec[i]) - box.begin();
		if (len <= 0) continue;
		ans = max(ans, (int)(lower_bound(all(spec), spec[i] + len) - spec.begin() - i + onSpec[len]));
	}
	return ans;
}

void solve() {
	int n, m;
	vector<int> posBox, negBox, posSpec, negSpec;
	scanf("%d%d", &n, &m);
	while(n--) {
		int x;
		scanf("%d", &x);
		if (x > 0)
			posBox.push_back(x);
		else
			negBox.push_back(-x);
	}
	while(m--) {
		int x;
		scanf("%d", &x);
		if (x > 0)
			posSpec.push_back(x);
		else
			negSpec.push_back(-x);
	}
	printf("%d\n", solve(posBox, posSpec) + solve(negBox, negSpec));
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