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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll cr, pr[maxn];

bool p2(ll x) {
    return (x == (x & (-x)));
}

void append(ll p, ll nn, ll kk) {
    // cout << "append" _ p _ nn _ kk << nl;
    ll i, z;

    if (nn <= 0 || nn % 2 == 0) {
        cout << "NO" << nl; exit(0);
    }

    if (nn == 1) {
        if (kk != 0) {
            cout << "NO" << nl; exit(0);
        }
        pr[cr] = p; cr++; return;
    }

    if (kk <= 1) {
        if (p2(nn + 1) ^ (kk == 0)) {
            cout << "NO" << nl; exit(0);
        }
        pr[cr] = p;
        for (i = 1; i < nn; i++) pr[cr + i] = cr + (i - 1) / 2;
        cr += nn; return;
    }

    if (nn == 9 && kk == 2) {
        cout << "NO" << nl; exit(0);
    }
    pr[cr] = p; z = cr; cr++;
    if ((p2(nn - 1) && kk == 2) || (nn == 11 && kk == 3)) {
        append(z, 3, 0); append(z, nn - 4, kk - 1);
    } else {
        append(z, 1, 0); append(z, nn - 2, kk - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;

    cr = 1; append(0, n, k);

    cout << "YES" << nl;
    for (i = 1; i <= n; i++) cout << pr[i] << ' ';
    cout << nl;

    return 0;
}