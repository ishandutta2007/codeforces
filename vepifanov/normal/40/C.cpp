#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n, x;
int m, y;

int main() {
	cin >> n >> x >> m >> y;
	if (x > y) { swap (x, y); swap (n, m); }
	ll ans = 1;
	if (x + n < y + m) ans += min ((y + m) - (x + n), m);
	if (x - n < y - m) ans += min ((y - m) - (x - n), n);
	for (int i = 1; i <= n; i++)
		if (y >= x + i) {
			int d = max (min (i + x - (y - m), 2 * i), 0);
			ans += int (d > 0) + max (d - 1, 0) * 2 - int (d == 2 * i);
		} else {
			int h = (i + x - 1) - y;
			int d = max (min (m - h, y - h - (x - i)), 0);
			ans += int (d > 0) + max (d - 1, 0) * 2 - int (d == y - h - (x - i));
		}
	cout << ans << endl;
	return 0;
}