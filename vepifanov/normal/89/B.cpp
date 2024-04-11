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

int n;
int m, r = 0;
map<string, int> all;
string name[100];
vi v[100];
vector<pair<string, pair<ll, ll> > > res;
ll bord[100], spac[100], w[100], h[100], was[100], t[100];
char s[200];

int get (string s) {
    if (all.find (s) != all.end ()) re all[s];
    all[s] = r;
    name[r] = s;
    r++;
    re r - 1;
}

pair<ll, ll> calc (int x) {
    if (t[x] == 0 || was[x]) re mp (w[x], h[x]);
    if (sz (v[x]) == 0) re mp (0, 0);
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        pair<ll, ll> tmp = calc (v[x][i]);
        if (t[x] == 1) {
            h[x] = max (h[x], tmp.se);
            w[x] += tmp.fi;
        } else {
            w[x] = max (w[x], tmp.fi);
            h[x] += tmp.se;
        }
    }
    w[x] += 2 * bord[x];
    h[x] += 2 * bord[x];
    if (t[x] == 1) w[x] += (sz (v[x]) - 1) * spac[x]; else h[x] += (sz (v[x]) - 1) * spac[x];
    re mp (w[x], h[x]);
}

int main () {
    scanf ("%d", &n);
    gets (s);
    for (int i = 0; i < n; i++) {
        gets (s);
        for (int i = 0; s[i]; i++)
            if (s[i] == '.' || s[i] == '_' || s[i] == '(' || s[i] == ')' || s[i] == ',')
                s[i] = ' ';
        stringstream in (s);
        string a, b, c;
        ll x, y;
        in >> a;
        if (a == "Widget") {
            in >> b >> x >> y;
            int j = get (b);
            w[j] = x;
            h[j] = y;
            t[j] = 0;
        } else
        if (a == "HBox" || a == "VBox") {
            in >> b;
            int j = get (b);
            w[j] = h[j] = 0;
            t[j] = int (a == "HBox") + 2 * int (a == "VBox");
            spac[j] = bord[j] = 0;
        } else {
            int j = get (a);
            in >> b;
            if (b == "pack") {
                in >> c;
                int k = get (c);
                v[j].pb (k);
            } else {
                in >> c >> x;
                if (c == "border") bord[j] = x; else spac[j] = x;
            }
        }
    }
    memset (was, 0, sizeof (was));
    for (int i = 0; i < r; i++)
        res.pb (mp (name[i], calc (i)));
    sort (all (res));
    for (int i = 0; i < r; i++) printf ("%s %I64d %I64d\n", res[i].fi.c_str (), res[i].se.fi, res[i].se.se);
    return 0;
}