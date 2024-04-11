#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b[maxn], x, y;
ll st[1300010], h[maxn], ns[maxn];
stack<array<ll, 2>> q;

ll add(ll x, ll p) {
    ll r;
    array<ll, 2> o = {x, p};
    while (!q.empty() && q.top() > o) q.pop();
    if (q.empty()) r = 0;
    else r = q.top()[1];
    q.push(o);
    return r;
}

ll rmq(ll v, ll tl, ll tr, ll l, ll r) {
    // cout << "rmq " << v _ tl _ tr _ l _ r << nl;
    if (l > r)
        return -INF;
    if (l == tl && r == tr) {
        return st[v];
    }
    ll tm = (tl + tr) / 2;
    return max(rmq(v*2, tl, tm, l, min(r, tm)),
           rmq(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    // cout << "upd " << v _ tl _ tr _ pos _ new_val << nl;
    if (tl == tr) {
        st[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (i = 1; i <= n; i++) {
        ns[i] = add(h[i], i);
    }

    /* for (i = 1; i <= n; i++) {
        cout << ns[i] << ' ';
    }
    cout << nl; */

    for (i = 1; i <= n; i++) {
        if (ns[i] == 0) x = -INF;
        else x = rmq(1, 0, n + 5, ns[i], ns[i]);
        y = rmq(1, 0, n + 5, ns[i], i - 1) + b[i];
        // cout << x _ y << nl;
        update(1, 0, n + 5, i, max(x, y));
    }

    /* for (i = 1; i <= n; i++) {
        cout << rmq(1, 0, n + 5, i, i) << ' ';
    } */

    cout << rmq(1, 0, n + 5, n, n) << nl;

    return 0;
}