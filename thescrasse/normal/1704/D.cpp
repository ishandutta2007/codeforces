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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> m >> n;
        vector<vector<ll>> v(m + 1, vector<ll>(n + 1, 0));
        vector<ll> score(m + 1, 0);
        array<ll, 2> mn = {INF, 0}, mx = {-INF, 0};

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                ll a; cin >> a; score[i] += (j * a);
            }
            mn = min(mn, {score[i], i}); mx = max(mx, {score[i], i});
        }

        cout << mx[1] _ mx[0] - mn[0] << nl;
    }

    return 0;
}