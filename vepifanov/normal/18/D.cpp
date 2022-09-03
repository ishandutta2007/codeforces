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
	int val[1000];
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
int m;
int v[5001];
int l[2001];
tlong res[5001];
tlong p2[2001];

int main() {
	cin >> n;
	for (int i = 0; i <= 2000; i++) l[i] = -1;
	for (int i = 0; i < n; i++) {
		v[i] = -1;
		string s;
		int x;
		cin >> s >> x;
		if (s == "win") v[i] = x; else l[x] = i;
	}
	p2[0] = fint (1);
	for (int i = 1; i <= 2000; i++) p2[i] = p2[i - 1] * 2;
	res[n] = fint (0);
	for (int i = n - 1; i >= 0; i--) {
		res[i] = res[i + 1];
		if (v[i] >= 0 && l[v[i]] != -1 && l[v[i]] > i) {
			tlong tmp = res[l[v[i]]] + p2[v[i]];
			if (tmp >= res[i]) res[i] = tmp;
		}
	}
	print (res[0], true);
	return 0;
}