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
#define prev PREV
                         
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
int k, p;
int x[100000];
int y[100000];
ll z[100000];
set<ii> all;

int can (ll h) {
    all.clear ();
    for (int i = 0; i < n; i++) {
        z[i] = h;
        int tmp = -1;
        if (z[i] - (ll)m * y[i] < 0) tmp = z[i] / y[i]; else
        if (z[i] - (ll)m * y[i] < x[i]) tmp = m;
        if (tmp != -1) all.insert (mp (tmp, i));
    }
    for (int i = 0; i < m && !all.empty (); i++)
        for (int j = 0; j < k && !all.empty (); j++) {
            ii cur = *all.begin ();
            all.erase (all.begin ());
            if (cur.fi <= i) re 0;
            z[cur.se] += p;
            int tmp = -1;
            if (z[cur.se] - (ll)m * y[cur.se] < 0) tmp = (z[cur.se] + y[cur.se] - 1) / y[cur.se]; else
            if (z[cur.se] - (ll)m * y[cur.se] < x[cur.se]) tmp = m;
            if (tmp != -1) all.insert (mp (tmp, cur.se));
        }
    re int (all.empty ());
}

int main () {
    scanf ("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
    ll l = -1, r = 1e18;
    while (r - l > 1) {
        ll s = (l + r) / 2;
        if (can (s)) r = s; else l = s;
    }
    cout << r << endl;
    return 0;
}