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
int m, k;
map<string, int> all;
int t[200], l[4], r[4], fa[5], fb[5], mt[200], cost[200], w[200], fr, p[200], o; 
bool was[100][1440 * 30 + 1], use[100][1440 * 30 + 1];
int res[100][1440 * 30 + 1];
int ra[200], rb[200], ri[200];

bool myless (int i, int j) {
	re mt[i] < mt[j];
}

int go (int ct, int i) {
	if (i == n) re 0;
	if (was[i][ct]) re res[i][ct];
	was[i][ct] = 1;
	res[i][ct] = go (ct, i + 1);
	use[i][ct] = 0;
	if (cost[p[i]] >= 0 && ct + t[w[p[i]]] <= mt[p[i]]) {
		int tmp = go (ct + t[w[p[i]]], i + 1) + cost[p[i]];
		if (tmp > res[i][ct]) {
			res[i][ct] = tmp;
			use[i][ct] = 1;
		}
	}
	re res[i][ct];
}

int out (int ct, int i) {
	if (i == n) re 0;
	if (use[i][ct] == 0) out (ct, i + 1); else {
		ri[o] = p[i] + 1;
		ra[o] = ct;
		rb[o] = ct + t[w[p[i]]] - 1;
		o++;
		out (ct + t[w[p[i]]], i + 1);
	}
	re 0;
}

int print (int x) {
	printf (" %d", x / fr + 1);
	x %= fr;
	for (int i = 0; i < 5; i++)
		if (fb[i] - fa[i] > 0)
			if (fb[i] - fa[i] <= x) x -= fb[i] - fa[i]; else { x += fa[i]; break; }
	printf (" %02d:%02d", x / 60, x % 60);
	re 0;
}


int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		all[s] = i;
	}
	for (int i = 0; i < m; i++) cin >> t[i];
	fr = 24 * 60;
	for (int i = 0; i < 4; i++) {
		int a, b, c, d;
		scanf ("%d:%d-%d:%d", &a, &b, &c, &d);
		l[i] = a * 60 + b;
		r[i] = c * 60 + d + 1;
		fr -= r[i] - l[i];
	}
	if (fr == 0) {
		printf ("0\n0\n");
		re 0;
	}
	fa[0] = 0;
	fb[0] = l[0];
	for (int i = 1; i < 4; i++) {
		fa[i] = r[i - 1];
		fb[i] = l[i];
	}
	fa[4] = r[3];
	fb[4] = 1440;
	for (int i = 0; i < n; i++) {
		int ok = 1;
		string s;
		int a, b, d;
		cin >> s;
		if (all.count (s)) w[i] = all[s]; else ok = 0;
		cin >> d;
		scanf ("%d:%d", &a, &b);
		a = a * 60 + b;
		int c = 0;
		for (int j = 0; j < 4; j++)
			if (a >= r[j])
				c += r[j] - l[j];
			else
			if (a >= l[j])
				c += a - l[j];
		a -= c;
		mt[i] = (d - 1) * fr + a;
		cin >> cost[i];
		p[i] = i;
		if (!ok) cost[i] = -1;
	}
	sort (p, p + n, myless);
	printf ("%d\n", go (0, 0));
	out (0, 0);
	printf ("%d\n", o);
	for (int i = 0; i < o; i++) {
		printf ("%d", ri[i]);	
		print (ra[i]);
		print (rb[i]);
		printf ("\n");
	}
	return 0;
}