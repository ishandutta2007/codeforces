#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

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
        cin >> n >> s; flag[0] = 1; flag[1] = 1;
        s.pb(s[0]);
        for (i = 0; i < n; i++) {
            if (s[i] == '<') flag[0] = 0;
            else if (s[i] == '>') flag[1] = 0;
        }

        if (flag[0] + flag[1] > 0) {
            cout << n << nl; continue;
        }

        res = 0;
        for (i = 0; i < n; i++) {
            if (s[i] == '-' || s[i + 1] == '-') res++;
        }

        cout << res << nl;
    }

    return 0;
}