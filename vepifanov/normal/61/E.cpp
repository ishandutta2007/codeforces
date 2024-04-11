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
int r = 1;
int m;
int f[1000001];
int x[1000001];
ii y[1000001];
int cl[1000001], cr[1000001];

int get (int x) {
	int s = 0;
	while (x > 0) {
		s += f[x];
		x = (x & (x + 1)) - 1;
	}
	re s;
}

int add (int x) {
	while (x <= r) {
		f[x]++;
		x |= x + 1;
	}
	re 0;
}

int main() {
	scanf ("%d", &n);	
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		y[i] = mp (x[i], i);
	}
	sort (y, y + n);
	for (int i = 0; i < n; i++) {
		if (i > 0 && y[i - 1].fi != y[i].fi) r++;
		x[y[i].se] = r;
	}
	memset (f, 0, sizeof (f));
	for (int i = 0; i < n; i++) {
		cl[i] = get (r - x[i]);
		add (r - x[i] + 1);
	}
	memset (f, 0, sizeof (f));
	for (int i = n - 1; i >= 0; i--) {
		cr[i] = get (x[i] - 1);
		add (x[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) ans += (ll)cl[i] * cr[i];
	cout << ans << endl;
	return 0;
}