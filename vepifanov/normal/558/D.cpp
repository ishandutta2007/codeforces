#include <cstdio>
#include <numeric>
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
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
vector<pair<ll, ll> > w;
vector<pair<ll, int> > v;

pair<ll, ll> get (int i, ll x) {
    pair<ll, ll> y (x, x);
	while (i < n) {
		y.fi = y.fi * 2;
		y.se = y.se * 2 + 1;
		i++;
	}
	re y;
}

int main () {
	scanf ("%d%d", &n, &m);
	pair<ll, ll> cur = get (1, 1);
	for (int i = 0; i < m; i++) {
		int h, t;
		ll l, r;
		cin >> h >> l >> r >> t;
		if (t == 1) {
			cur.fi = max (cur.fi, get (h, l).fi);
			cur.se = min (cur.se, get (h, r).se);
		} else {
		    w.pb (mp (get (h, l).fi, get (h, r).se));
//			v.pb (mp (get (h, l).fi), 1);
//			v.pb (mp (get (h, r).se), -1);
		}
	}
	if (cur.fi > cur.se) {
		printf ("Game cheated!\n");
		re 0;
	}
	for (int i = 0; i < sz (w); i++) {
		if (w[i].fi > cur.se || w[i].se < cur.fi)
			continue;
		v.pb (mp (max (w[i].fi, cur.fi), 1));
		v.pb (mp (min (w[i].se, cur.se), -1));
	}	
	sort (all (v));
	int bal = 0;
	ll cnt = 0;
	ll last = -1;
	if (v.empty ()) {
		cnt = cur.se - cur.fi + 1;
		last = cur.se;	
	} else {
	    if (v[0].fi > cur.fi) {
	    	cnt += v[0].fi - cur.fi;
	    	last = v[0].fi - 1;
	    }
		for (int i = 0; i + 1 < sz (v); i++) {
			bal += v[i].se;
			if (bal == 0 && v[i + 1].fi > v[i].fi + 1) {
				cnt += v[i + 1].fi - v[i].fi - 1;
				last = v[i + 1].fi - 1;
			}			
		}
		if (v[sz (v) - 1].fi < cur.se) {
			cnt += cur.se - v[sz (v) - 1].fi;
			last = cur.se;
		}
    }
    if (cnt == 0) {
    	printf ("Game cheated!\n");
    	re 0;
    }
    if (cnt > 1) {
    	printf ("Data not sufficient!\n");
    	re 0;
    }
    cout << last << endl;
    return 0;
}