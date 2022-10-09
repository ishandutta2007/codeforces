// 1237E
// Balanced Binary Search Trees

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;

    v.pb(1); v.pb(2);

    while (v.back() <= 1000000) {
        x = v.back();
        if (x % 2) {
            v.pb(2 * x - 1); v.pb(2 * x);
        } else {
            v.pb(2 * x); v.pb(2 * x + 1);
        }
    }

    res = 0;
    for (auto u : v) {
        if (u == n) res++;
    }

    cout << res << nl;

    return 0;
}