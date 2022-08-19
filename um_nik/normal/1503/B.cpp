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

vector<pii> a[2];

void makeMove(pii s, int x) {
	cout << x << " " << s.first << " " << s.second << endl;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++) {
			a[(x + y) % 2].push_back(mp(x, y));
		}
	while(!a[0].empty() && !a[1].empty()) {
		int b;
		cin >> b;
		if (b == 1) {
			makeMove(a[1].back(), 2);
			a[1].pop_back();
		} else {
			makeMove(a[0].back(), 1);
			a[0].pop_back();
		}
	}
	while(!a[0].empty()) {
		int b;
		cin >> b;
		if (b != 3) {
			makeMove(a[0].back(), 3);
			a[0].pop_back();
		} else {
			makeMove(a[0].back(), 1);
			a[0].pop_back();
		}
	}
	while(!a[1].empty()) {
		int b;
		cin >> b;
		if (b != 3) {
			makeMove(a[1].back(), 3);
			a[1].pop_back();
		} else {
			makeMove(a[1].back(), 2);
			a[1].pop_back();
		}
	}
	

	return 0;
}