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
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> s; s = '#' + s; k = 0;

        for (i = 1; i <= n; i++) {
            if (s[i] != s[i - 1]) k++;
        }

        res = max(a * n + b * n, a * n + b * ((k + 2) / 2));
        cout << res << nl;
    }

    return 0;
}