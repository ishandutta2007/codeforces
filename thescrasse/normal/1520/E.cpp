#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, ps[maxn], ss[maxn];
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
        cin >> n >> s; s = '#' + s; res = 0;

        for (i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + (s[i] == '*');
        }

        ss[n + 1] = 0;
        for (i = n; i >= 1; i--) {
            ss[i] = ss[i + 1] + (s[i] == '*');
        }

        for (i = 1; i <= n; i++) {
            if (s[i] == '.') res += min(ps[i], ss[i]);
        }

        cout << res << nl;
    }

    return 0;
}