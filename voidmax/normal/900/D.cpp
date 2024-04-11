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
#define x first
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
using namespace std;
		  
template <typename T1, typename T2> inline void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
		  
const string FILENAME = "input";
		  
typedef pair<double, double> point;

const int p = 1e9 + 7;

int sum(int a, int b) {
	a += b;
	return a >= p ? a - p : a;
}

int mul(long long a, int b) {
	return a * b % p;
}

int powx(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

int n, m;
map<int, int> ans;
vector<int> dev;


void calc(int d) {
	int res = p - powx(2, m / d - 1);
	for (int j : dev) {
		if (j % d != 0) continue;
		res = sum(res, ans[j]);
	}
	ans[d] = sum(0, p - res);
}

int main() {
	srand(time(0));
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 1; i * i <= m; ++i) {
		if (m % i == 0) {
			dev.pb(i);
			if (i * i != m) dev.pb(m / i);
		}
	}
	sort(dev.rbegin(), dev.rend());
	for (int i : dev) calc(i);	
	cout << ans[n] << endl;
}