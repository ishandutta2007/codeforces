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

ll ask(ll x) {
    ll y;
    cout << "? " << x << nf;
    cin >> y; a[x] = y;
    return y;
}

ll clm(ll x) {
    cout << "! " << x << nf;
    exit(0);
}

void src(ll x, ll y, ll z) {
    // cout << "src " << x _ y _ z << nl;
    if (z - x == 2) clm(y);

    ll w;
    if (y - x > z - y) {
        w = (x + y) / 2; ask(w);
        if (a[w] > a[y]) src(w, y, z);
        else src(x, w, y);
    } else {
        w = (y + z) / 2; ask(w);
        if (a[w] > a[y]) src(x, y, w);
        else src(y, w, z);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n; a[0] = INF; a[n + 1] = INF;
    if (n <= 3) {
        for (i = 1; i <= n; i++) ask(i);
        for (i = 1; i <= n; i++) {
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) clm(i);
        }
    }

    ask(1); ask(2); ask(n - 1); ask(n);
    if (a[1] < a[2]) clm(1);
    if (a[n] < a[n - 1]) clm(n);

    if (a[1] > a[n]) src(1, n - 1, n);
    else src(1, 2, n);

    return 0;
}