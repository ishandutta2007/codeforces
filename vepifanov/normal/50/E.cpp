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
ii v[12000000];

ll mysqrt (ll x) {
	ll y = sqrt (x);
	while (sqr (y + 1) <= x) y++;
	re y;
}

ll calc (ll x) {
	if (x < 1) re 0;
	re mysqrt (x);
}

bool l1 (ii a, ii b) {
	re a.se < b.se;
}

int main() {
	scanf ("%d%d", &n, &m);	
	ll ans = 0;
	for (ll a = -n; a < 0; a++) {
		ll l = max (a * a - m, (ll)1);
		ll r = max (a * a - 1, (ll)1);
		ans += (r - l + 1) - calc (r) + calc (l - 1);
	}
	ans *= 2;
	int o = 0;
	for (ll b = 1; b <= n; b++) {
		ll r = mysqrt (b * b - 1);
		ll l = mysqrt (max (b * b - m, (ll)0));
		while (l * l < b * b - m) l++;
//		printf ("%I64d: %I64d %I64d\n", b, l, r);
		if (l <= r) {
			v[o++] = mp (-b - r, -b - l);
			v[o++] = mp (-b + l, -b + r);
		}
	}
	sort (v, v + o, l1);
	ii c;
	for (int i = 0; i < o; i++) {
		if (i > 0 && v[i].fi <= c.se) c.se = v[i].se; else c = v[i];
		if (i + 1 == o || v[i + 1].fi > c.se) ans += c.se - c.fi + 1;
//		printf ("%d %d %I64d\n", c.fi, c.se, ans);
	}
	cout << ans << endl;

	return 0;
}