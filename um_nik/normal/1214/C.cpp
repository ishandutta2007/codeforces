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

bool check(string s) {
	int bal = 0;
	for (char c : s) {
		if (c == '(')
			bal++;
		else
			bal--;
		if (bal < 0) return false;
	}
	return bal == 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	string s;
	cin >> n >> s;
	int p = 0;
	while(p < n && s[p] == '(') p++;
	if (p == n) {
		cout << "No\n";
		return 0;
	}
	if (check(s.substr(0, p) + s.substr(p + 1, n - p - 1) + ")")) {
		cout << "Yes\n";
		return 0;
	}
	p = n - 1;
	while(p >= 0 && s[p] == ')') p--;
	if (p == -1) {
		cout << "No\n";
		return 0;
	}
	if (check("(" + s.substr(0, p) + s.substr(p + 1, n - p - 1))) {
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";

	return 0;
}