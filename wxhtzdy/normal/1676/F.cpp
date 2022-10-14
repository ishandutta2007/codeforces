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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	vector<int> vals;
	for (auto& pp : cnt)
		vals.push_back(pp.first);
	int ans = -1, l = 0, r = -1;
	for (int i = 0; i < vals.size(); i++) {
		if (cnt[vals[i]] < k)
			continue;
		int ptr = i;
		while (ptr + 1 < vals.size() && cnt[vals[ptr + 1]] >= k && vals[ptr + 1] == vals[ptr] + 1)
			ptr++;
		if (ans < ptr - i + 1) {
			ans = ptr - i + 1;
			l = vals[i];
			r = vals[ptr];
		}
		i = ptr;
	}
	if (ans == -1)
		cout << ans << '\n';
	else
		cout << l << " " << r << '\n';
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