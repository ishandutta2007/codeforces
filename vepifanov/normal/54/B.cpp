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

int n;
int m;
string s[20];
set<pair<ii, string> > all;

pair<ii, string> get (int i, int j, int x, int y) {
        string w1 = "", w2 = "", w3 = "", w4 = "";
	for (int p = 0; p < x; p++)
		for (int q = 0; q < y; q++)
			w1 += s[i + p][j + q];
	for (int p = x - 1; p >= 0; p--)
		for (int q = y - 1; q >= 0; q--)
			w2 += s[i + p][j + q];
	for (int q = 0; q < y; q++)
		for (int p = x - 1; p >= 0; p--)
			w3 += s[i + p][j + q];
	for (int q = y - 1; q >= 0; q--)
		for (int p = 0; p < x; p++)
			w4 += s[i + p][j + q];
	re min (min (mp (mp (x, y), w1), mp (mp (x, y), w2)), min (mp (mp (y, x), w3), mp (mp (y, x), w4)));
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	int ans = 0, rx = n, ry = m;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			if (n % x == 0 && m % y == 0) {
				all.clear ();
				int ok = 1;
				for (int i = 0; i < n; i += x)
					for (int j = 0; j < m; j += y) {
						pair<ii, string> w = get (i, j, x, y);
						if (all.count (w)) ok = 0;
						all.insert (w);
					}
				if (ok) {
					ans++;
					if (x * y < rx * ry || x * y == rx * ry && x < rx) {
						rx = x;
						ry = y;
					}
				}
			}
	printf ("%d\n%d %d\n", ans, rx, ry);
	return 0;
}