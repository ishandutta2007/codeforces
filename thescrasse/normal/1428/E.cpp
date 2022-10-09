// 1428E
// Carrots for Rabbits

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, p, x, c;
priority_queue<array<ll, 3>> pq;

ll vl(ll p, ll x) {
    ll k = a[p];
    ll q = k / x; ll r = k % x;
    ll res = (x - r) * q * q + r * (q + 1) * (q + 1);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> a[i]; pq.push({vl(i, 1) - vl(i, 2), i, 2});
        res += a[i] * a[i];
    }

    for (i = 0; i < k - n; i++) {
        x = pq.top()[0]; p = pq.top()[1]; c = pq.top()[2]; pq.pop();
        // cout << x << ' ' << p << ' ' << c << ' ' << nl;
        res -= x; pq.push({vl(p, c) - vl(p, c + 1), p, c + 1});
    }

    cout << res;

    return 0;
}