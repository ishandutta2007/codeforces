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

const int mod = 1000*1000*1000+7;

int n;
int m;
int res[2000];
int f[200001];
int rf[200001];
ii v[2000];
int k;

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int cnk (int n, int k) {
    re (((ll)f[n] * rf[k]) % mod * rf[n - k]) % mod;
}

int main () {
    f[0] = rf[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        f[i] = ((ll)f[i - 1] * i) % mod;
        rf[i] = ((ll)rf[i - 1] * power (i, mod - 2)) % mod;
    }
    scanf ("%d%d%d", &n, &m, &k); n--; m--;
    for (int i = 0; i < k; i++) {
        scanf ("%d%d", &v[i].fi, &v[i].se);
        v[i].fi--;
        v[i].se--;
    }
    sort (v, v + k);
    memset (res, 0, sizeof (res));
    int ans = cnk (n + m, m);
    for (int i = 0; i < k; i++) {
        res[i] = cnk (v[i].fi + v[i].se, v[i].fi);
        for (int j = 0; j < i; j++)
            if (v[j].se <= v[i].se)
                res[i] = (res[i] - (ll)res[j] * cnk ((v[i].fi - v[j].fi) + (v[i].se - v[j].se), v[i].fi - v[j].fi) % mod + mod) % mod;
        ans = (ans - (ll)res[i] * cnk (n - v[i].fi + m - v[i].se, m - v[i].se) % mod + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}