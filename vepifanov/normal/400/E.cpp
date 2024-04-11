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
int m;
ll ans = 0;
set<ii> all[20];
int w[20][100000];

int upd (int t, int i, int k) {
    if (w[t][i] == 0 && k == 1) {
        ii x (i, i);
        if (i > 0 && w[t][i - 1] == 1) {
            set<ii>::iterator it = all[t].lower_bound (mp (i, i));
            it--;
            ans -= ((ll)(it->se - it->fi + 1) * (it->se - it->fi + 2) / 2) << t;
            x.fi = it->fi;
            all[t].erase (it);
        }
        if (i + 1 < n && w[t][i + 1] == 1) {
            set<ii>::iterator it = all[t].lower_bound (mp (i, i));
            ans -= ((ll)(it->se - it->fi + 1) * (it->se - it->fi + 2) / 2) << t;
            x.se = it->se;
            all[t].erase (it);
        }
        all[t].insert (x);
        ans += ((ll)(x.se - x.fi + 1) * (x.se - x.fi + 2) / 2) << t;
    } else
    if (w[t][i] == 1 && k == 0) {
        set<ii>::iterator it = all[t].lower_bound (mp (i, 1e9));
        it--;
        ans -= ((ll)(it->se - it->fi + 1) * (it->se - it->fi + 2) / 2) << t;
        int a = it->fi, b = it->se;
        all[t].erase (it);
        if (a < i) {
            all[t].insert (mp (a, i - 1));
            ans += ((ll)(i - a) * (i - a + 1) / 2) << t;
        }
        if (i < b) {
            all[t].insert (mp (i + 1, b));
            ans += ((ll)(b - i) * (b - i + 1) / 2) << t;
        }
    }
    w[t][i] = k;
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        for (int j = 0; j < 20; j++)
            upd (j, i, (x >> j) & 1);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--;
        for (int j = 0; j < 20; j++)
            upd (j, a, (b >> j) & 1);
        printf ("%I64d\n", ans);
    }
    return 0;
}