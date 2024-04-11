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
priority_queue<ll> x, y;

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
        for (i = 1; i <= n; i++) {
            cin >> a; x.push(-a);
        }
        for (i = 1; i <= n; i++) {
            cin >> b; y.push(-b);
        }

        flag[0] = 1;
        for (i = 1; i <= n; i++) {
            a = -x.top(); x.pop();
            b = -y.top(); y.pop();
            if (a != b - 1 && a != b) flag[0] = 0;
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}