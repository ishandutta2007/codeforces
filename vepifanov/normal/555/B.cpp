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
ll x[200000];
ll y[200000];
ll a[200000];
ll b[200000];
vector<pair<ll, ii> > v;
int res[200000];
set<pair<ll, int> > all;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%I64d%I64d", &x[i], &y[i]);
    for (int i = 0; i + 1 < n; i++) {
        a[i] = x[i + 1] - y[i];
        b[i] = y[i + 1] - x[i];
        v.pb (mp (a[i], mp (0, i)));
        v.pb (mp (b[i], mp (2, i)));
    }
    for (int i = 0; i < m; i++) {
        ll x;
        scanf ("%I64d", &x);
        v.pb (mp (x, mp (1, i)));
    }
    sort (all (v));
    for (int i = 0; i < sz (v); i++)
        if (v[i].se.fi == 0)
            all.insert (mp (b[v[i].se.se], v[i].se.se));
        else
        if (v[i].se.fi == 1) {
            if (!all.empty ()) {
                pair<ll, int> x = *all.begin();
                res[x.se] = v[i].se.se;
                all.erase (all.begin ());
            }   
        } else
        if (all.find (mp (b[v[i].se.se], v[i].se.se)) != all.end ()) {
            printf ("No\n");
            re 0;
        }
    printf ("Yes\n");
    for (int i = 0; i < n - 1; i++) printf ("%d ", res[i] + 1);
    printf ("\n");
    return 0;
}