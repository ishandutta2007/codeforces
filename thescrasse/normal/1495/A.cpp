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
vector<ll> va, vb;
long double rs, mm;

long double dist(ll a, ll b) {
    long double k = a * a + b * b;
    return sqrt(k);
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
        cin >> n; va.clear(); vb.clear();
        for (i = 1; i <= 2 * n; i++) {
            cin >> a >> b;
            if (a == 0) vb.pb(abs(b));
            else va.pb(abs(a));
        }

        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());

        rs = 0;
        for (i = 0; i < n; i++) {
            rs += dist(va[i], vb[i]);
            // cout << rs << nl;
        }

        cout << fixed << setprecision(20);
        cout << rs << nl;
    }

    return 0;
}