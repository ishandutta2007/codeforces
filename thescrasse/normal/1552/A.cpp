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

ll i, i1, j, k, k1, tc, n, m, res, flag[10], a, b;
string s, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> tc;
    while (tc--) {
        cin >> n >> s; t = s; res = 0;
        sort(t.begin(), t.end());
        s = '#' + s; t = '#' + t;

        for (i = 1; i <= n; i++) {
            if (s[i] != t[i]) res++;
        }

        cout << res << nl;
    }

    return 0;
}