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

const int p10[6] = {1, 10, 100, 1000, 10000, 100000};

const int base = 1000000;

struct tlong {
	int len;
	int val[200];
	int clear () {
		len = 0;
		memset (val, 0, sizeof (val));
		return 0;
	}
};

tlong fint (int x) {
	tlong a; a.clear ();
	a.len = 0;
	while (x) {
		a.val[a.len++] = x % base;
		x /= base;
	}
	return a;
}

tlong fstring (string s) {
	tlong a; a.clear ();
	a.len = (sz (s) + 5) / 6;
	for (int i = 0; i < sz (s); i++)
		a.val[i / 6] += (s[i] - '0') * p10[i % 6];
	return a;
}

int print (tlong a, bool nextline) {
	if (a.len == 0) printf ("0");
	for (int i = a.len; i > 0; i--)
		if (i == a.len)
			printf ("%d", a.val[i - 1]);
		else
			printf ("%06d", a.val[i - 1]);
	if (nextline) printf ("\n");
}

bool operator== (tlong a, tlong b) {
	if (a.len != b.len) return false;
	for (int i = a.len - 1; i >= 0; i--)
		if (a.val[i] != b.val [i]) return false;
	return true;
}

tlong operator- (tlong a, tlong b) {
	tlong c;
	c.clear ();
	c.len = max (a.len, b.len);
	for (int i = 0; i < c.len; i++) {
		c.val[i] = c.val[i] + a.val[i] - b.val[i];
		if (c.val[i] < 0) {
			c.val[i + 1]--;
			c.val[i] += base;
		}
	}
	while (c.len > 0 && c.val[c.len - 1] == 0) c.len--;
	return c;		
}

tlong operator* (tlong a, int b) {
	int r = 0;
	for (int i = 0; i < a.len; i++) {
		a.val[i] = a.val[i] * b + r;
		r = a.val[i] / base;
		a.val[i] = a.val[i] % base;
	}
	while (r) {
		a.val[a.len] = r % base;
		a.len++;
		r /= base;
	}
	while (a.len > 0 && a.val[a.len - 1] == 0) a.len--;
	return a;		
}

int n;
int m;
vector<ll> v[20];

tlong res[600][310];

string s;

int main() {
	cin >> s;
	reverse (all (s));
	tlong cur = fstring (s);
	res[1][1] = fint (2);
	res[2][1] = fint (13);
	for (int i = 1; i < 600; i++) {
		if (i > 2) {
			int a = (i - 1) / 2;
			int b = i / 2;
			int c = (i + 1) / 2;
			for (int j = 1; j <= a; j++)
				res[i][j] = res[i - 2][j] * 12;
			res[i][c] = res[i - 1][b] * 13 - res[i - 2][a] * 12;
		}
		for (int j = 1; j <= (i + 1) / 2; j++)
			if (res[i][j] == cur) {
				printf ("YES\n");
				printf ("1\n%d\n%d\n", i, (i + 1) / 2 - 1);
				for (int k = 1; k <= (i + 1) / 2; k++)
					if (k != j) print (res[i][k], true);
				re 0;
			}
	}
	printf ("NO\n");
	return 0;
}