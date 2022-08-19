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

const int N = 100100;
int n, X, Y;
int a[N];
vector<int> forCol[N];

void solve() {
	scanf("%d%d%d", &n, &X, &Y);
	for (int i = 1; i <= n + 1; i++)
		forCol[i].clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		forCol[a[i]].push_back(i);
	}
	if (X > Y) {
		printf("NO\n");
		return;
	}
	Y -= X;
	int bad = 1;
	while(!forCol[bad].empty()) bad++;
	for (int i = 0; i < n; i++)
		a[i] = bad;
	set<pii> setik;
	for (int i = 1; i <= n + 1; i++) {
		setik.insert(mp((int)forCol[i].size(), i));
	}
	while(X > 0) {
		int c = setik.rbegin()->second;
		setik.erase(mp((int)forCol[c].size(), c));
		a[forCol[c].back()] = c;
		forCol[c].pop_back();
		setik.insert(mp((int)forCol[c].size(), c));
		X--;
	}
	int mx = setik.rbegin()->second;
	vector<pii> cc;
	for (int j = 0; j < (int)forCol[mx].size(); j++)
		cc.push_back(mp(mx, forCol[mx][j]));
	for (int c = 1; c <= n + 1; c++) {
		if (c == mx) continue;
		for (int j = 0; j < (int)forCol[c].size(); j++)
			cc.push_back(mp(c, forCol[c][j]));
	}
	int z = (int)forCol[mx].size();
	if (2 * ((int)cc.size() - z) < Y) {
		printf("NO\n");
		return;
	}
	for (int i = 0; Y > 0 && i < (int)cc.size(); i++) {
		int p = (i + z) % (int)cc.size();
		if (cc[i].first != cc[p].first) {
			a[cc[i].second] = cc[p].first;
			Y--;
		}
	}
	assert(Y == 0);
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
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