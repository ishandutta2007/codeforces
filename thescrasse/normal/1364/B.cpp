#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, u, v;
stack<ll> s;
vector<ll> w;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        w.clear();
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        /* if (n == 2) {
            cout << abs(a[0] - a[1]) << nl;
            cout << a[0] << ' ' << a[1] << nl;
            continue;
        } */

        s.push(a[0]); s.push(a[1]);
        for (i = 2; i < n; i++) {
            v = s.top(); s.pop();
            u = s.top(); s.pop();
            s.push(u); s.push(v);
            k = a[i];
            if ((u < v && v < k) || (u > v && v > k)) {
                s.pop();
            }
            s.push(k);
        }

        while (!s.empty()) {
            w.push_back(s.top()); s.pop();
        }

        reverse(w.begin(), w.end());

        res = w.size();
        cout << res << nl;
        for (auto u : w) {
            cout << u << ' ';
        }
        cout << nl;
    }

    return 0;
}