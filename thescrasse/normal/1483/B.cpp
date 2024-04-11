#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll pv[maxn], nx[maxn], jm[maxn], jmr[maxn], l;
vector<ll> rs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; m = n; rs.clear();
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            if (i == n) nx[i] = 1;
            else nx[i] = i + 1;
            if (i == 1) pv[i] = n;
            else pv[i] = i - 1;
            jm[i] = i; jmr[i] = i;
        }

        /* if (n == 1) {
            if (a[1] == 1) cout << "1 1 " << nl;
            else cout << "0 " << nl;
            continue;
        } */

        l = 1; k = 0;
        while (true) {
            /* cout << "l = " << l << nl;
            for (i = 1; i <= n; i++) {
                cout << "i: " << i _ pv[i] _ nx[i] _ jmr[i] _ jm[i] << nl;
            }
            cout << nl; */

            if (k == 0) {
                l = nx[jm[l]];
                k++;
            } else if (__gcd(a[l], a[pv[l]]) == 1) {
                rs.pb(l); nx[pv[l]] = nx[l]; pv[nx[l]] = pv[l];
                if (jm[l] != l) {
                    jm[nx[l]] = jm[l]; jmr[jm[nx[l]]] = nx[l];
                }
                if (jm[l] == l) k = 0;
                else k = 1;
                l = nx[jm[l]];
                m--;
            } else {
                jmr[l] = jmr[pv[l]]; jm[jmr[l]] = l; l = nx[jm[l]];
                k++;
            }
            if (k >= n + 5) break;
            if (m == 1) {
                if (a[l] == 1) rs.pb(l);
                break;
            }
        }

        cout << rs.size() << ' ';
        for (auto u : rs) cout << u << ' ';
        cout << nl;

        // cout << "---" << nl;
    }

    return 0;
}