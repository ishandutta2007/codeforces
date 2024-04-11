// 1254B2
// Send Boxes to Alice (Hard Version)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define maxn 1000010
#define pb push_back

ll i, i1, j, k, k1, t, n, m, res, flag, a[maxn], b[maxn], tot, ps[maxn], ss[maxn], pt, er[maxn];
vector<ll> pf;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i]; tot += a[i];
    }

    for (i = 0; i < maxn; i++) {
        er[i] = i;
    }

    for (i = 2; i < maxn; i++) {
        if (er[i] == i) {
            for (j = 2 * i; j < maxn; j += i) {
                er[j] = i;
            }
        }
    }

    if (tot == 1) {
        cout << -1; return 0;
    }

    k = tot;
    for (i = 2; i * i <= tot; i++) {
        if (tot % i == 0 && er[i] == i) {
            pf.pb(i);
            while (k % i == 0) k /= i;
        }
    }
    if (k > sqrt(tot)) pf.pb(k);

    res = INF;
    for (auto u : pf) {
        pt = 0;
        for (i = 0; i < n; i++) b[i] = a[i] % u;
        ps[0] = b[0];
        for (i = 1; i < n; i++) ps[i] = (ps[i - 1] + b[i]) % u;
        for (i = 0; i < n - 1; i++) {
            pt += min(ps[i], u - ps[i]);
        }
        res = min(res, pt);
        // cout << u << ' ' << pt << endl;
    }

    cout << res;

    return 0;
}