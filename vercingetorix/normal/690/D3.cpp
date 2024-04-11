#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back

const int MAXN = 105;
const ll MOD = 1000003;

typedef ll Matr[MAXN][MAXN];

int n;

void mult(const Matr& a, const Matr& b, Matr& c) {
    forn(i, n) {
        forn(j, n) {
            c[i][j] = 0;
            forn(k, n) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= MOD;
        }
    }
}

void getPow(const Matr& a, ll b, Matr& res) {
    forn(i, n) {
        forn(j, n) {
            res[i][j] = int(i == j);
        }
    }
    Matr t;
    for (int i = 30; i >= 0; i--) {
        memcpy(t, res, sizeof(Matr));
        mult(t, t, res);
        if (b & (1ll << i)) {
            memcpy(t, res, sizeof(Matr));
            mult(t, a, res);
        }
    }
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int w, h, c;
    cin >> c >> w >> h;
    Matr a;
    forn(i, w + 1) {
        if (i == 0) {
            a[i][1] = h;
        } else if (i < w) {
            a[i][i + 1] = h;
        }
        a[i][0] = 1;
    }
    n = w + 1;
    /*
    forn(i, w + 1) {
        forn(j, w + 1) {
            cerr << a[i][j] << " ";
        }
        cerr << endl;
    }
     */
    Matr d;
    getPow(a, c, d);
    ll ans = 0;
    /*
    forn(i, w + 1) {
        forn(j, w + 1) {
            cerr << d[i][j] << " ";
        }
        cerr << endl;
    }
     */
    forn(i, w + 1) {
        ans = (ans + d[0][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}