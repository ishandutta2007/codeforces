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
ll l;
vector<ll> x, y;

vector<ll> parse(ll n) {
    vector<ll> v;
    while (n != 0) {
        v.pb(n % 10); n /= 10;
    }
    v.pb(0);
    reverse(v.begin(), v.end());
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; res = INF;

        for (i = 0; i <= 59; i++) {
            x = parse(n); y = parse((ll)1 << i);

            l = 1;
            for (j = 1; j < x.size(); j++) {
                if (l < y.size() && x[j] == y[l]) l++;
            }

            res = min(res, (ll)x.size() + (ll)y.size() - 2 * l);
        }

        cout << res << nl;
    }

    return 0;
}