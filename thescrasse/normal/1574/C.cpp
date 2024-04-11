#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)3e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll tt, x, y, q;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a; v.pb(a); tt += a;
    }
    sort(v.begin(), v.end());

    cin >> q;
    while (q--) {
        cin >> x >> y; res = INF;

        auto it = lower_bound(v.begin(), v.end(), x);
        if (it != v.end()) res = min(res, max((ll)0, y - tt + (*it)));

        if (it != v.begin()) {
            it--;
            res = min(res, x - (*it) + max((ll)0, y - tt + (*it)));
        }

        cout << res << nl;
    }

    return 0;
}