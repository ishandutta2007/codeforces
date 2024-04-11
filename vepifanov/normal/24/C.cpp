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

tlong fint (long long x) {
	tlong a; a.clear ();
	a.len = 0;
	while (x) {
		a.val[a.len++] = x % 10;
		x /= 10;
	}
	return a;
}

int print (tlong a, bool nextline) {
	if (a.len == 0) printf ("0");
	for (int i = a.len; i > 0; i--)
		printf ("%d", a.val[i - 1]);
	if (nextline) printf ("\n");
}

tlong operator+ (tlong a, tlong b) {
	tlong c;
	c.clear ();
	c.len = max (a.len, b.len);
	int r = 0;
	for (int i = 0; i < c.len; i++) {
		c.val[i] = a.val[i] + b.val[i] + r;
		r = c.val[i] / 10;
		c.val[i] %= 10;
	}
	while (r) {
		c.val[c.len] = r % 10;
		c.len++;
		r /= 10;
	}
	return c;		
}

tlong operator* (tlong a, int b) {
	tlong c; c.clear ();
	c.len = a.len;
	int r = 0;
	for (int i = 0; i < c.len; i++) {
		long long tmp = r + (long long)a.val[i] * b;
		c.val[i] = tmp % 10;
		r = tmp / 10;
	}
	while (r) {
		c.val[c.len] = r % 10;
		c.len++;
		r /= 10;
	}
	return c;		
}

int n;
int cx[100000], cy[100000], q[100000];

int main() {
	long long m;
	int x, y;
	scanf ("%d%I64d", &n, &m);
	scanf ("%d%d", &x, &y);
	for (int i = 0; i < n; i++) scanf ("%d%d", &cx[i], &cy[i]);
	for (int i = 0; i < n && m - i > 0; i++)
		if (((m - i + n - 1) / n) & 1)
			q[i] = 2;
		else
			q[i] = 0;
	int k = (m - 1) % n;
	for (int i = n - 1; i > 0; i -= 2) 
		q[(k + i) % n] = -q[(k + i) % n];
	if (m & 1) { x = -x; y = -y; }
	for (int i = 0; i < n; i++) {
		x += q[i] * cx[i];
		y += q[i] * cy[i];
	}
	printf ("%d %d\n", x, y);
	return 0;
}