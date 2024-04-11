#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 500010
#define maxa 10000010 // change

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
int f[maxa], mb[maxa];
ll g[maxa], p2[maxn], dd, gg;
vector<int> pr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    p2[0] = 1;
    for (i = 1; i < maxn; i++) p2[i] = (2 * p2[i - 1]) % mod;

    for (i = 1; i < maxa; i++) g[i] = i;
    for (i = 2; i < maxa; i++) {
        if (g[i] != i) continue;
        pr.pb(i);
        for (j = 2 * i; j < maxa; j += i) g[j] = i;
    }

    mb[1] = 1;
    for (i = 2; i < maxa; i++) {
        if (g[i] == g[i / g[i]]) mb[i] = 0;
        else mb[i] = -mb[i / g[i]];
    }

    /* for (i = 1; i <= 30; i++) cout << mb[i] << ' ';
    cout << nl; */

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; f[a[i]]++;
    }

    for (auto u : pr) {
        for (i = (maxa - 1) / u; i >= 1; i--) {
            f[i] += f[u * i];
        }
    }

    for (i = 0; i < maxa; i++) g[i] = (p2[f[i]] + mod - 1) % mod;

    for (auto u : pr) {
        for (i = 1; i <= (maxa - 1) / u; i++) {
            g[i] = (g[i] - g[u * i] + mod) % mod;
        }
    }

    g[1] = 0;
    for (auto u : pr) {
        for (i = (maxa - 1) / u; i >= 1; i--) {
            g[i] = (g[i] + g[u * i]) % mod;
        }
    }

    for (i = 1; i < maxa; i++) res = (res + g[i] * f[i] * mb[i]) % mod;
    res = (res + mod) % mod;

    cout << res << nl;

    return 0;
}