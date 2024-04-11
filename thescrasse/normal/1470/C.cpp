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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x, bsl, bsm, bsu, tq;

ll ask(ll a) {
    ll x;
    cout << "? " << (a % n) + 1 << nf;
    cin >> x;
    return x;
}

ll clm(ll x) {
    cout << "! " << (x % n) + 1 << nf;
    exit(0);
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n >> k; a = -1; b = -1;
    while (true) {
        x = uniform_int_distribution<ll>(0, n - 1)(rng);
        m = ask(x); tq++;
        if (m < k) a = x;
        else if (m > k) b = x;

        if (tq == 990) {
            while (true) {}
        }
        if (a != -1 && b != -1) break;
    }

    // cout << a _ b << nl;

    if (a > b) b += n;
    bsl = a; bsu = b;
    while (true) {
        bsm = (bsl + bsu) / 2;
        m = ask(bsm); tq++;
        if (m == k) clm(bsm);
        else if (m > k) bsu = bsm - 1;
        else bsl = bsm + 1;

        if (tq == 990) {
            while (true) {}
        }
    }

    return 0;
}