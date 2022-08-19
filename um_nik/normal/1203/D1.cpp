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

bool isSubseq(string t, string s) {
	int pos = 0;
	for (char c : t) {
		while(pos < (int)s.length() && s[pos] != c) pos++;
		if (pos == (int)s.length()) return false;
		pos++;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	string s, t;
	cin >> s >> t;
	int n = s.length();
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (isSubseq(t, s.substr(0, i) + s.substr(j, n - j)))
				ans = max(ans, j - i);
		}
	cout << ans << endl;

	return 0;
}