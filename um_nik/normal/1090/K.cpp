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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<psi, vector<int>> a;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int it = 1; it <= n; it++) {
		string s, p;
		cin >> s >> p;
		int mask = 0;
		for (char c : p) {
			mask |= 1 << (int)(c - 'a');
		}
		while(!s.empty() && ((mask >> (int)(s.back() - 'a')) & 1))
			s.pop_back();
		a[mp(s, mask)].push_back(it);
	}
	cout << (int)a.size() << "\n";
	for (auto t : a) {
		cout << (int)t.second.size();
		for (int x : t.second)
			cout << " " << x;
		cout << "\n";
	}

	return 0;
}