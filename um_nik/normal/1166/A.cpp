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

const int A = 26;
vector<string> a[A];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	string s;
	while(n--) {
		cin >> s;
		a[(int)(s[0] - 'a')].push_back(s);
	}
	int ans = 0;
	for (int c = 0; c < A; c++) {
		int z = (int)a[c].size();
		int x = z / 2;
		z -= x;
		ans += x * (x - 1) / 2 + z * (z - 1) / 2;
	}
	cout << ans << endl;

	return 0;
}