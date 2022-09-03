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
ii v[100000];
pair<int, ii> w[100000];
double ans;
int ai, aj;
int a, b;
              
int upd (int i, int j) {
    double res = sqrt (sqr (a + 0.0) + sqr (v[i].fi + 0.0)) + sqrt (sqr (b - a + 0.0) + sqr (v[i].fi - w[j].fi + 0.0)) + w[j].se.fi;
    if (res < ans) {
        ans = res;
        ai = v[i].se;
        aj = w[j].se.se;
    }
    re 0;
}

int main () {
    scanf ("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i].fi);
        v[i].se = i + 1;
    }
    for (int i = 0; i < m; i++) {
        scanf ("%d", &w[i].fi);
        w[i].se.se = i + 1;
    }
    for (int i = 0; i < m; i++)
        scanf ("%d", &w[i].se.fi);
    sort (v, v + n);
    sort (w, w + m);
    ans = 1e18;
    ai = aj = 0;
    int i = 0;
    for (int j = 0; j < m; j++) {
        while (i + 1 < n && (ll)v[i + 1].fi * b <= (ll)w[j].fi * a) i++;
        upd (i, j);
        if (i + 1 < n) upd (i + 1, j);
    }
    printf ("%d %d\n", ai, aj);
    return 0;
}