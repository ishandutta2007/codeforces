#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
vector<ll> v;

ll solve(ll b, vector<ll> v) {
    if (b == -1) return 1;

    vector<ll> l, r;
    for (auto u : v) {
        if ((u >> b) & 1) l.pb(u);
        else r.pb(u);
    }

    if ((ll)l.size() < (ll)r.size()) swap(l, r);
    if (l.empty()) return 0;
    else if (r.empty()) return solve(b - 1, l);
    else return max(solve(b - 1, l), solve(b - 1, r)) + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a; v.pb(a);
    }

    cout << n - solve(31, v);

    return 0;
}