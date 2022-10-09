#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 5000010

ll i, i1, j, k[2], k1, t, n, m, res, flag[10], a[maxn], b, p[2], f[2][2][2], pw[2][maxn];
bool eq[maxn];
vector<ll> h[2];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> s; n = s.size();

    for (i = 0; i <= n; i++) eq[i] = true;

    p[0] = 1000000007; p[1] = 998244353;
    k[0] = uniform_int_distribution<ll>(201, 250)(rng);
    k[1] = uniform_int_distribution<ll>(251, 300)(rng);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 200; j++) {
            h[i].push_back(j);
        }
        shuffle(h[i].begin(), h[i].end(), rng);
        pw[i][0] = 1;
        for (j = 1; j <= n; j++) {
            pw[i][j] = (pw[i][j - 1] * k[i]) % p[i];
            // cout << i << ' ' << j << ' ' << pw[i][j] << nl;
        }
    }

    // cout << "ok" << nf;

    for (i = 0; i < 2; i++) {
        f[i][0][0] = 0; f[i][1][0] = 0;
        for (j = 1; j <= n; j++) {
            // cout << i << ' ' << j << nf;
            f[i][0][1] = (f[i][0][0] * k[i] + h[i][(ll)s[j - 1]]) % p[i];
            f[i][0][0] = f[i][0][1];
            f[i][1][1] = (f[i][1][0] + h[i][(ll)s[j - 1]] * pw[i][j - 1]) % p[i];
            f[i][1][0] = f[i][1][1];

            // cout << f[i][0][0] << ' ' << f[i][1][0] << nl;
            if (f[i][0][0] != f[i][1][0]) eq[j - 1] = false;
        }
    }

    res = 1; a[1] = 1;
    for (i = 2; i <= n; i++) {
        if (eq[i - 1]) a[i] = a[i / 2] + 1;
        else a[i] = 0;
        res += a[i];
    }

    cout << res;

    return 0;
}