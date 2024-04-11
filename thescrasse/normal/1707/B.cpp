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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;

struct zector {
    ll zero_count;
    vector<ll> v;

    zector(): zero_count(0) {}

    void ins(ll x) {
        if (x == 0) zero_count++;
        else v.pb(x);
    }

    void reduce() {
        sort(v.begin(), v.end());
        zector w;
        if (zero_count >= 1 && (!v.empty())) w.ins(v[0]);
        for (ll i = 1; i < (ll)v.size(); i++) w.ins(v[i] - v[i - 1]);
        if (zero_count >= 1) zero_count--;
        zero_count += w.zero_count; v = w.v;
    }

    ll get() {
        assert(zero_count >= 1 || (!v.empty()));
        if (v.empty()) return 0;
        return v[0];
    }

    void dbg() {
        cout << "zero_count =" _ zero_count << nl;
        for (auto u : v) cout << u << ' ';
        cout << nl;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        zector v;
        for (i = 1; i <= n; i++) {
            cin >> a; v.ins(a);
        }

        for (i = 1; i <= n - 1; i++) v.reduce(); //, v.dbg();
        cout << v.get() << nl;
    }

    return 0;
}