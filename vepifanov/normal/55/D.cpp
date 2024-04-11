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
bool was[20][256][2520][2];
bool pg[256][2520];
ll res[20][256][2520][2];
int y[20];
int g5[5][10], g7[7][10], g8[8][10], g9[9][10];

inline int hash (int a, int b, int c, int d) {
	re a + 5 * (b + 7 * (c + 8 * d));
}

int good (int mask, int p5, int p7, int p8, int p9) {
	re pg[mask][hash (p5, p7, p8, p9)];
}

int pgood (int mask, int p5, int p7, int p8, int p9) {
	if ((mask & 1) && (p8 & 1)) re 0;
	if ((mask & 2) && (p9 % 3 != 0)) re 0;
	if ((mask & 4) && (p8 & 3)) re 0;
	if ((mask & 8) && (p5 != 0)) re 0;
	if ((mask & 16) && ((p8 & 1) || (p9 % 3 != 0))) re 0;
	if ((mask & 32) && (p7 != 0)) re 0;
	if ((mask & 64) && (p8 != 0)) re 0;
	if ((mask & 128) && (p9 != 0)) re 0;
	re 1;
}

int get (int &mask, int &p5, int &p7, int &p8, int &p9, int &f, int k) {
	if (k > 0) f = 0;
	if (k > 1) mask |= (1 << (k - 2));
	p5 = g5[p5][k];
	p7 = g7[p7][k];
	p8 = g8[p8][k];
	p9 = g9[p9][k];
	re 0;
}

ll go (int r, int mask, int p5, int p7, int p8, int p9, int f) {
	if (r == 0) re good (mask, p5, p7, p8, p9);
	int h = hash (p5, p7, p8, p9);
	if (was[r][mask][h][f]) re res[r][mask][h][f];
	int nmask, np5, np7, np8, np9, nf;
	was[r][mask][h][f] = 1;
	ll cur = 0;
	for (int j = f; j < 10; j++) {
		nmask = mask; np5 = p5; np7 = p7; np8 = p8; np9 = p9; nf = f;
		get (nmask, np5, np7, np8, np9, nf, j);
		cur += go (r - 1, nmask, np5, np7, np8, np9, nf);
	}
	res[r][mask][h][f] = cur;
	re cur;
}

ll calc (ll x) {
	if (x == 0) re 0;
	int r = 0;
	while (x) {
		y[r++] = x % 10;
		x /= 10;
	}
	ll cur = 0;
	for (int j = 1; j < r; j++)
		cur += go (j, 0, 0, 0, 0, 0, 1);
	int mask = 0, p5 = 0, p7 = 0, p8 = 0, p9 = 0, f = 1;
	int nmask, np5, np7, np8, np9, nf;
	for (int j = r - 1; j >= 0; j--) {
		for (int k = f; k < y[j]; k++) {
			nmask = mask; np5 = p5; np7 = p7; np8 = p8; np9 = p9; nf = f;
			get (nmask, np5, np7, np8, np9, nf, k);
			cur += go (j, nmask, np5, np7, np8, np9, nf);
		}
		get (mask, p5, p7, p8, p9, f, y[j]);
	}
	cur += good (mask, p5, p7, p8, p9);
	re cur;
}

int main() {
	for (int mask = 0; mask < 256; mask++)
		for (int p5 = 0; p5 < 5; p5++)
			for (int p7 = 0; p7 < 7; p7++)
				for (int p8 = 0; p8 < 8; p8++)
					for (int p9 = 0; p9 < 9; p9++)
						pg[mask][hash (p5, p7, p8, p9)] = pgood (mask, p5, p7, p8, p9);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 10; j++)
			g5[i][j] = (i * 10 + j) % 5;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 10; j++)
			g7[i][j] = (i * 10 + j) % 7;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 10; j++)
			g8[i][j] = (i * 10 + j) % 8;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++)
			g9[i][j] = (i * 10 + j) % 9;
	int tt;
	cin >> tt;
	for (int it = 0; it < tt; it++) {
		ll l, r;
		cin >> l >> r;
		cout << calc (r) - calc (l - 1) << endl;
	}
	return 0;
}