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
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool isPal(string s) {
	int n = s.length();
	for (int i = 0; i < n; i++)
		if (s[i] != s[n - 1 - i])
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	bool allEq = true;
	int n = s.length();
	for (int i = 0; i < n; i++)
		if (n % 2 == 0 || i != n / 2)
			allEq &= s[0] == s[i];
	if (allEq) {
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 1; i < n - 1; i++) {
		string p = s.substr(i, n - i) + s.substr(0, i);
		if (p == s || !isPal(p)) continue;
		cout << 1 << endl;
		return 0;
	}
	cout << 2 << endl;

	return 0;
}