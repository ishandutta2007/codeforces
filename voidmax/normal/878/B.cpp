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
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;
  
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

typedef long long ll;
typedef long double ld;

const string FILENAME = "input";

long long n, k, m;
long long ans;
vector <int> a;
vector <pair <long long, int>> res;
vector <int> queL, queR;

int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n >> k >> m;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int L = 0, R;
	while (L < n) {
		R = L;
		while (R < n && a[L] == a[R]) {
			++R;
		}
		int s = R - L, c = a[L];
		L = R;
		s %= k;
		if (s == 0) {
			continue;
		}
		if (res.size() && res.back().x == c) {
			res.back().y += s;
			res.back().y %= k;
			if (res.back().y == 0) {
				res.pop_back();
				continue;
			}
		} else {
			res.pb({c, s});
		}
	}
	L = 0, R = (int)res.size() - 1;
	while (L < R) {
		if (res[L].x != res[R].x) {
			for (int i = L; i <= R; ++i) {
				ans += res[i].y * m;
			}
			cout << ans << endl;
			return 0;
		}
		ans += res[L].y + res[R].y;
		queL.pb(res[L].y);
		queR.pb(res[R].y);
		if ((res[L].y + res[R].y) % k == 0) {
			++L, --R;
			continue;
		}
		ans += ((res[L].y + res[R].y) % k) * (m - 1);
		++L, --R;
		for (int i = L; i <= R; ++i) {
			ans += res[i].y * m;
		}
		cout << ans << endl;
		return 0;
	}
	if (L == R) {
		ans += res[L].y * m % k;
		if (res[L].y * m % k == 0) {
			while (queL.size()) {
				if ((queL.back() + queR.back()) % k == 0) {
					ans -= queL.back() + queR.back();
					queL.pop_back();
					queR.pop_back();
				} else {
					ans -= (queL.back() + queR.back());
					ans += (queL.back() + queR.back()) % k;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}