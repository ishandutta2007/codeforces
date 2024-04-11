#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, c[4];
string s;

bool solve(ll x) {
    ll i, fl;
    fl = 1;

    for (i = 1; i <= n; i++) {
        if (s[i] == 'A') {
            if (x & 1) a[i] = 1;
            else a[i] = -1;
        } else if (s[i] == 'B') {
            if (x & 2) a[i] = 1;
            else a[i] = -1;
        } else if (s[i] == 'C') {
            if (x & 4) a[i] = 1;
            else a[i] = -1;
        }
    }


    for (i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        if (a[i] < 0) fl = 0;
        if (i == n && a[i] != 0) fl = 0;
    }

    if (fl == 1) return true;
    else return false;
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
        cin >> s; n = s.size(); s = '#' + s;
        flag[0] = 0;
        for (i = 0; i < 8; i++) {
            if (solve(i)) flag[0] = 1;
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}