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
ll f[maxn];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> s; n = s.size(); s = '#' + s;
        for (i = 0; i <= 25; i++) f[i] = 0;

        for (i = n; i >= 1; i--) {
            a = (ll)s[i] - 'a';
            if (f[a] == 0) k = i; // i is the rightmost occurrence of a letter
            f[a]++;
        }
        // k is the minimum among the rightmost occurrences

        for (i = k; i <= n; i++) cout << s[i];
        cout << nl;
    }

    return 0;
}