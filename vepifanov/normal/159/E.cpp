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

vii v;
vii w[100000];
vi res;
ll cnt[100001];
int ri[100001], rj[100001];
int p[100000], q[100000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &p[i], &q[i]);
        v.pb (mp (p[i], i));
    }
    sort (all (v));
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i - 1].fi != v[i].fi) r++;
        w[r - 1].pb (mp (q[v[i].se], v[i].se));
    }
    ll ans = -1;
    int i1, j1, i2, j2;
    for (int i = 0; i < r; i++) {
        sort (all (w[i]));
        reverse (all (w[i]));
        ll cur = 0;
        for (int j = 1; j <= sz (w[i]); j++) {
            cur += w[i][j - 1].fi;
            for (int k = -1; k <= 1; k++)
                if (j + k > 0)
                    if (cnt[j + k] > 0 && ans < cnt[j + k] + cur) {
                        ans = cnt[j + k] + cur;
                        i1 = i;
                        j1 = j;
                        i2 = ri[j + k];
                        j2 = rj[j + k];
                    }
        }
        cur = 0;
        for (int j = 1; j <= sz (w[i]); j++) {
            cur += w[i][j - 1].fi;
            if (cnt[j] < cur) {
                cnt[j] = cur;
                ri[j] = i;
                rj[j] = j;
            }
        }
    }
    int a = 0, b = 0, c = int (j1 < j2);
    while (a < j1 || b < j2) {
        if (c) {
            res.pb (w[i2][b].se + 1);
            b++;
        } else {
            res.pb (w[i1][a].se + 1);
            a++;
        }
        c ^= 1;
    }
    printf ("%I64d\n%d\n", ans, sz (res));
    for (int i = 0; i < sz (res); i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}