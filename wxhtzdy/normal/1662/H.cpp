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

int w, l;
vector<int> cands;

void addDivs(int x) {
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			cands.pb(i);
			cands.pb(x / i);
		}
	}
}

bool check(int x) {
	if (x == 2) {
		if (w % 2 == 0 && l % 2 == 1)
			return true;
		if (w % 2 == 1 && l % 2 == 0)
			return true;
	}
	if (l % x == 0 && (w - 2) % x == 0) 
		return true;
	if (w % x == 0 && (l - 2) % x == 0)
		return true;
	if (l % x == 1 && w % x == 1)
		return true;
	return false;
}

void solve() {
	scanf("%d%d", &w, &l);
	cands.clear();
	addDivs(w);
	addDivs(w - 1);
	addDivs(w - 2);
	sort(all(cands));
	cands.erase(unique(all(cands)), cands.end());
	vector<int> ans;
	for (int i : cands) 
		if (check(i))
			ans.pb(i);
	printf("%d ", ans.size());
	for (int i : ans) printf("%d ", i);
	printf("\n");
}

int main()
{
	startTime = clock();

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}