#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

bool solve(ll n, ll m) {
    ll i, flag = 0, tt = 0, x;
    for (i = 1; i <= k; i++) {
        x = a[i] / n;
        if (x >= 2) tt += x;
        if (x >= 3) flag = 1;
    }

    if (tt < m) return false;
    if (flag == 0 && (m % 2) == 1) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (i = 1; i <= k; i++) {
            cin >> a[i];
        }

        if (solve(n, m) || solve(m, n)) cout << "Yes" << nl;
        else cout << "No" << nl;
    }

    return 0;
}