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

const int MAX = 512;

int n;
int m;
vi ra, rb;
int g[MAX][MAX], w[MAX], d[MAX][MAX], p[MAX][MAX];
int q[250000];

int out (int a, int b) {
	ra.pb (a + 1);
	rb.pb (b + 1);
	if (d[a][b] == 1) re 0;
	out (p[a][b] >> 10, p[a][b] & 1023);
	re 0;
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		g[a][w[a]++] = b;
		g[b][w[b]++] = a;
	}
	int l = 0, r = 1;
	q[0] = n - 1;
	memset (d, 0, sizeof (d));
	d[0][n - 1] = 1;
	int a, b, c, e;
	while (l < r) {
		a = q[l] >> 10;
		b = q[l] & 1023;
		int D = d[a][b] + 1, P = (a << 10) + b;
		if (a == n - 1 && b == 0) break;
		l++;       
		int *I = &g[a][0], *J = &g[b][0], *i, *j;
		int *II = I + w[a], *JJ = J + w[b];
		for (i = I; i != II; i++)
			for (j = J; j != JJ; j++) {
				c = *i;
				e = *j;
				if (c != e && !d[c][e]) {
					d[c][e] = D;
					p[c][e] = P;
					q[r++] = (c << 10) + e;
				}
			}
	}
	if (!d[n - 1][0]) { printf ("-1\n"); re 0; }
	printf ("%d\n", d[n - 1][0] - 1);
	out (n - 1, 0);
	reverse (all (ra));
	reverse (all (rb));
	for (int i = 0; i < ra.size (); i++) printf ("%d ", ra[i]);
	printf ("\n");
	for (int i = 0; i < rb.size (); i++) printf ("%d ", rb[i]);
	printf ("\n");
	return 0;
}