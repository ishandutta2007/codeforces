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
int m = 0;
vi v[300];
int q[300], l[300], r[300], c[300];

int go (int x, int p) {
	l[x] = n + 1;
	r[x] = -1;
	c[x] = 0;
	int ok = 0;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i];
		if (y != p) {
			ok = 1;
			if (go (y, x)) re 1;
			l[x] = min (l[x], l[y]);
			r[x] = max (r[x], r[y]);
			c[x] += c[y];
		}
	}
	if (!ok) { 
		c[x] = 1;
		l[x] = r[x] = q[x];
	}
//	printf ("%d %d = %d..%d\n", x + 1, c[x], l[x] + 1, r[x] + 1);
	if (r[x] - l[x] + 1 != c[x]) re 1;
	re 0;
}

bool myless (int i, int j) {
	return l[i] < l[j];
}

int go2 (int x, int p) {
	sort (all (v[x]), myless);
	printf ("%d ", x + 1);
	int ok = 0;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i];
		if (y != p) {
			ok = 1;
			go2 (y, x);
			printf ("%d ", x + 1);
		}
	}
	re 0;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	int x;
	while (scanf ("%d", &x) == 1) q[x - 1] = m++;
	if (go (0, 0)) {
		printf ("-1\n");
		re 0;
	}
	go2 (0, 0);
	printf ("\n");
	return 0;
}