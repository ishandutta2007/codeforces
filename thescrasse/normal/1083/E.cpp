#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define ld long double
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll x[maxn], y[maxn], dp[maxn], sz;
deque<array<ll, 2>> v;
vector<array<ll, 3>> w;

ll eval(array<ll, 2> a, ll x) {
    return (a[0] * x + a[1]);
}

ld int_x(array<ll, 2> a, array<ll, 2> b) {
    ld a0, a1, b0, b1;
    a0 = a[0]; a1 = a[1]; b0 = b[0]; b1 = b[1];
    return (b1 - a1) / (a0 - b0);
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
        cin >> x[i] >> y[i] >> a[i]; w.pb({x[i], y[i], a[i]});
    }
    v.pb({0, 0});

    sort(w.begin(), w.end());
    for (i = 1; i <= n; i++) {
        x[i] = w[i - 1][0]; y[i] = w[i - 1][1]; a[i] = w[i - 1][2];
    }

    for (i = 1; i <= n; i++) {
        while (true) {
            sz = v.size();
            if (sz == 1 || eval(v[0], y[i]) >= eval(v[1], y[i])) break;
            v.pop_front();
        }
        dp[i] = x[i] * y[i] - a[i] + eval(v[0], y[i]);
        res = max(res, dp[i]);

        array<ll, 2> o = {-x[i], dp[i]};
        while (true) {
            sz = v.size();
            if (sz == 1 || int_x(v[sz - 1], o) < int_x(v[sz - 2], o)) break;
            v.pop_back();
        }
        v.pb(o);
    }

    cout << res << nl;

    return 0;
}