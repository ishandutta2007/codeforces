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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, ps[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i];

        m = 0;
        for (i = 2; i <= n; i++) {
            m = max(m, (a[i] * 100 + k - 1) / k - ps[i - 1]);
        }

        cout << m << nl;
    }

    return 0;
}