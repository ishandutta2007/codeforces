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

const ll MOD = 1000003;
const int MAXN = 1e6;

ll f[MAXN], fRev[MAXN];

ll modPow(ll a, ll b) {
    ll d = 1;
    for (int i = 30; i >= 0; i--) {
        d = (d * d) % MOD;
        if (b & (1ll << i)) {
            d = (d * a) % MOD;
        }
    }
    return d;
}

ll getRev(ll a) {
    return modPow(a, MOD - 2);
}

ll choose(int k, int n) {
    return f[n] * fRev[k] % MOD * fRev[n - k] % MOD;
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    f[0] = fRev[0] = 1;
    forn(i, MAXN - 1) {
        f[i + 1] = f[i] * (i + 1) % MOD;
        fRev[i + 1] = getRev(f[i + 1]);
    }
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + choose(k - 1, i + k - 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}