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
ll tt;
priority_queue<ll> x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n; tt = 0;
        while (!x.empty()) x.pop();
        while (!y.empty()) y.pop();
        for (i = 1; i <= n; i++) {
            cin >> a; x.push(a); tt += a;
        }
        y.push(tt);

        flag[0] = 1;
        while (!x.empty()) {
            a = x.top(); b = y.top();
            if (a == b) {
                x.pop(); y.pop();
            } else if (a > b) {
                flag[0] = 0; break;
            } else {
                y.pop(); y.push(b / 2); y.push((b + 1) / 2);
            }
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}