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
        cin >> s; n = s.size(); k = 0; m = 0;
        for (i = n - 1; i >= 0; i--) {
            if (s[i] == 'A') k++;
            else k--;
            m = max(m, k);
        }

        res = m;
        if ((m + n) % 2) res++;
        cout << res << nl;
    }

    return 0;
}