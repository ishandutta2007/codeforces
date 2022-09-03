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

struct tlong {
	int len;
	int val[50];
	int clear () {
		len = 0;
		memset (val, 0, sizeof (val));
		return 0;
	}
};

const int base = 1000;

tlong fint (int x) {
	tlong a; a.clear ();
	a.len = 0;
	while (x) {
		a.val[a.len++] = x % base;
		x /= base;
	}
	return a;
}

int print (tlong a, bool nextline) {
	if (a.len == 0) printf ("0");
	for (int i = a.len; i > 0; i--)
		if (i == a.len)
			printf ("%d", a.val[i - 1]);
		else
			printf ("%03d", a.val[i - 1]);
	if (nextline) printf ("\n");
}

bool operator>= (tlong a, tlong b) {
	if (a.len > b.len) return true;
	if (a.len < b.len) return false;
	for (int i = a.len - 1; i >= 0; i--) {
		if (a.val[i] > b.val [i]) return true;
		if (a.val[i] < b.val [i]) return false;
	}
	return true;
}

tlong operator+ (tlong a, tlong b) {
	tlong c;
	c.clear ();
	c.len = max (a.len, b.len);
	int r = 0;
	for (int i = 0; i < c.len; i++) {
		c.val[i] = a.val[i] + b.val[i] + r;
		r = c.val[i] / base;
		c.val[i] %= base;
	}
	while (r) {
		c.val[c.len] = r % base;
		c.len++;
		r /= base;
	}
	return c;		
}

tlong operator* (tlong a, int b) {
	tlong c; c.clear ();
	c.len = a.len;
	int r = 0;
	for (int i = 0; i < c.len; i++) {
		int tmp = r + a.val[i] * b;
		c.val[i] = tmp % base;
		r = tmp / base;
	}
	while (r) {
		c.val[c.len] = r % base;
		c.len++;
		r /= base;
	}
	return c;		
}

tlong operator* (tlong a, tlong b) {
	tlong c; c.clear ();
	c.len = a.len + b.len - 1;
	for (int i = 0; i < a.len; i++)
		for (int j = 0; j < b.len; j++)
			c.val[i + j] += a.val[i] * b.val[j];
	int r = 0;
	for (int i = 0; i < c.len; i++) {
		c.val[i] += r;
		r = c.val[i] / base;
		c.val[i] %= base;
	}
	while (r) {
		c.val[c.len] = r % base;
		c.len++;
		r /= base;
	}
	return c;		
}

int n;
int m;
int s[701];
vi v[701];
tlong res[701][701];
tlong tmp;

int calc (int x, int p) {
	res[x][0] = res[x][1] = fint (1);
	s[x] = 1;
	for (int i = 0; i < v[x].size (); i++)
		if (v[x][i] != p) {
			int y = v[x][i];
			calc (y, x);
			for (int j = s[x] + s[y]; j >= 0; j--)
				for (int k = 0; k <= s[y]; k++)
					if (j - k >= 0 && j - k <= s[x]) {
						tmp = res[x][j - k] * res[y][k];
						if (!(res[x][j] >= tmp)) res[x][j] = tmp;
					}
			s[x] += s[y];
		}
	for (int i = 1; i <= s[x]; i++) {
		tmp = res[x][i] * i;
		if (!(res[x][0] >= tmp)) res[x][0] = tmp;
	}
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	calc (0, -1);
	print (res[0][0], true);
	return 0;
}