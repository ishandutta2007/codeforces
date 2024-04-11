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
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n, l, v1, v2;
int m;

vector<pair<ll, int> > v;
ll res[100001];

int add (ll l, ll r) {
    if (l < 0) {
        v.pb (mp (l + (ll)2 * ::l * (v1 + v2), 1));
        v.pb (mp (0, 1));
        v.pb (mp ((ll)2 * ::l * (v1 + v2), -1));
        v.pb (mp (r, -1));
    } else {
        v.pb (mp (l, 1));
        v.pb (mp (r, -1));
    }
}

int main () {
    scanf ("%d%d%d%d", &n, &l, &v1, &v2);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        add ((ll)x * (v1 + v2) - (ll)l * v2, (ll)x * (v1 + v2));
    }
    v.pb (mp (0, 0));
    v.pb (mp ((ll)2 * l * (v1 + v2), 0));
    sort (all (v));
    int cur = 0;
    for (int i = 0; i < sz (v); i++) {
        cur += v[i].se;
        if (i + 1 < sz (v) && v[i + 1].fi != v[i].fi) res[cur] += v[i + 1].fi - v[i].fi;
    }
    for (int i = 0; i <= n; i++) printf ("%.10f\n", (res[i] + 0.0) / ((ll)2 * l * (v1 + v2)));
    return 0;
}