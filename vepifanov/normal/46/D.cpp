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
int m, l, b, f;
ii v[102];
int x[102], y[102];

int main() {
	scanf ("%d%d%d%d", &l, &b, &f, &n);
	int r = 2;
	v[0] = mp (-b, -b);
	v[1] = mp (l + f, l + f);
	for (int i = 0; i < n; i++) {
		int t, d;
		scanf ("%d%d", &t, &d);
		if (t == 1) {
			int ok = 1;
			for (int j = 0; j + 1 < r; j++)
				if (v[j + 1].fi - v[j].se >= b + f + d) {
					x[i] = v[j].se + b;
					y[i] = x[i] + d;
					printf ("%d\n", x[i]);
					for (int k = r; k - 1 > j; k--) v[k] = v[k - 1];
					v[j + 1] = mp (x[i], y[i]);
					r++;
					ok = 0;
					break;
				}
			if (ok) printf ("-1\n");
		} else {
			d--;
			for (int j = 0; j < r; j++)
				if (v[j].fi == x[d]) {
					for (int k = j; k + 1 < r; k++) v[k] = v[k + 1];
					r--;
				}
		}
	}
	return 0;
}