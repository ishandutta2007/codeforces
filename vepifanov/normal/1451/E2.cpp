#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const string qu[3] = {"AND", "OR", "XOR"};

int n;
int m;
int res[16];
int f[1 << 16];
ii can[1 << 16];
int fi0[1 << 16];
int fi1[1 << 16];
int ans[1 << 16];

int ask (int t, int i, int j) {
	printf ("%s %d %d\n", qu[t].c_str (), i + 1, j + 1);
	fflush (stdout);
	int x;
	scanf ("%d", &x);
	re x;
}

void upd (int a, int b, int c) {
	for (int i = 0; i < m; i++)
		if ((((a ^ b) >> i) & 1) == 0)
			res[i] = ((c >> i) & 1) ^ ((a >> i) & 1);
}

int main () {
	scanf ("%d", &n);
	int nn = n - 1;
	m = 0;
	while ((1 << m) < n) m++;
	for (int i = 0; i < m; i++) res[i] = -1;
	for (int i = 0; i < n; i++) fi0[i] = fi1[i] = -1;
	for (int i = 1; i < n; i++) {
		f[i] = ask (2, 0, i);
		if (fi0[f[i]] == -1) fi0[f[i]] = i; else
		if (fi1[f[i]] == -1) fi1[f[i]] = i;
	}
	int ok = 0;
	for (int i = 0; i < n; i++)
		if (fi1[i] != -1) {
			int cur = ask (0, fi0[i], fi1[i]);
			upd (i, i, cur);
			ok = 1;
			break;
		}
	if (!ok) {
		for (int i = 0; i < n; i++) can[i] = mp (-1, -1);
		for (int i = 0; i < n; i++) {
			if (fi0[i] == -1) continue;
			for (int j = 0; j < m; j++) {
				if (fi0[i ^ (1 << j)] != -1)
					can[nn ^ (1 << j)] = mp (i, i ^ (1 << j));
				if (fi0[i ^ nn ^ (1 << j)] != -1)
					can[(1 << j)] = mp (i, i ^ nn ^ (1 << j));
			}
			if (m > 2)
				for (int j = 0; j < m; j++)
					for (int k = j + 1; k < m; k++) {
						if (fi0[i ^ (1 << j) ^ (1 << k)] != -1)
							can[nn ^ (1 << j) ^ (1 << k)] = mp (i, i ^ (1 << j) ^ (1 << k));
						if (fi0[i ^ nn ^ (1 << j) ^ (1 << k)] != -1)
							can[(1 << j) ^ (1 << k)] = mp (i, i ^ nn ^ (1 << j) ^ (1 << k));
					}
		}
		for (int i = 0; i < n; i++)
			if (can[i].fi != -1 && can[nn ^ i].fi != -1) {
				upd (can[i].fi, can[i].se, ask (0, fi0[can[i].fi], fi0[can[i].se]));
				upd (can[nn ^ i].fi, can[nn ^ i].se, ask (0, fi0[can[nn ^ i].fi], fi0[can[nn ^ i].se]));
				ok = 1;
				break;
			}
	}
	assert (ok);
	for (int i = 0; i < m; i++) assert (res[i] != -1);
	for (int i = 0; i < m; i++) ans[0] |= (res[i] << i);
	for (int i = 1; i < n; i++) ans[i] = ans[0] ^ f[i];
	printf ("!");
	for (int i = 0; i < n; i++) printf (" %d", ans[i]);
	printf ("\n");
	fflush (stdout);
	re 0;
}