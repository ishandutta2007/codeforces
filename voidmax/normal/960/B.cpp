#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

typedef long double base;
typedef pair<base, base> point;

const int MAXN = 10000;

int n, c, v1, v2;
long long ans;
long long a[MAXN], b[MAXN];
multiset<int> v;

int main() {
	srand(time(0));
	//read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n >> v1 >> v2;
	c = v1 + v2;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) {
		//if (a[i] != b[i]) {
		long long k = abs(a[i] - b[i]);
		ans += k * k;
		v.insert(k);
	}
	while (c) {
		long long k = *v.rbegin();
		v.erase(v.find(k));
		ans -= k * k;
		v.insert(abs(k - 1));
		--c;
		ans += (k - 1) * (k - 1);
	}
	cout << ans << endl;
}