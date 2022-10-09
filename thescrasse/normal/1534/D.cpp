#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll dist[maxn];
set<array<ll, 2>> st;

void ask(ll x) {
    ll i, d, a, b;
    cout << "? " << x << nf;
    for (i = 1; i <= n; i++) {
        cin >> d;
        if (x == 1 && i != 1) {
            dist[i] = d; flag[d % 2]++;
        }
        if (d == 1) {
            a = x; b = i;
            if (a < b) swap(a, b);
            st.insert({a, b});
        }
    }
}

void clm() {
    cout << "!" << nf;
    for (auto u : st) cout << u[0] _ u[1] << nf;
    exit(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n;

    ask(1);

    if (flag[0] <= flag[1]) {
        for (i = 2; i <= n; i++) {
            if (dist[i] % 2 == 0) ask(i);
        }
    } else {
        for (i = 2; i <= n; i++) {
            if (dist[i] % 2) ask(i);
        }
    }

    clm();

    return 0;
}