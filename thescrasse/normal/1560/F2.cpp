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
ll sz, cn, l, vis[20];
vector<ll> v;

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
        cin >> n >> k; res = INF; cn = 0;
        for (i = 0; i <= 9; i++) vis[i] = 0;

        v = parse(n);

        sz = (ll)v.size() - 1; m = 0; res = 0; flag[1] = 0;
        for (i = 1; i <= sz; i++) {
            // cout << "i, v[i] = " << i _ v[i] << nl;
            for (j = 0; j <= 9; j++) {
                if (flag[1] == 0 && j < v[i]) continue;
                vis[j]++;
                if (vis[j] == 1) cn++;
                if (j != v[i]) flag[1] = 1;

                flag[0] = 0;
                if (cn < k || flag[1] == 1) flag[0] = 1;
                if (cn > k) flag[0] = 2;

                m = -1;
                for (l = 0; l <= 9; l++) {
                    if (vis[l] >= 1) m = l;
                }

                for (l = i + 1; l <= sz; l++) {
                    if (flag[0] == 0 && v[l] > m) flag[0] = 2;
                    else if (flag[0] != 2 && v[l] < m) flag[0] = 1;
                }

                // cout << "j, f, cn = " << j _ flag[0] _ cn << nl;

                if (flag[0] == 2) {
                    vis[j]--;
                    if (vis[j] == 0) cn--;
                } else {
                    res = 10 * res + j;
                    break;
                }
            }
        }

        cout << res << nl;
    }

    return 0;
}