#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, ps[maxn];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> s;

    ps[0] = 2 * (s[0] == '1') - 1;
    for (i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + 2 * (s[i] == '1') - 1;
    }

    if (ps[n - 1] == 0) {
        cout << 2 << nl;
        for (i = 0; i < n; i++) {
            cout << s[i];
            if (i == 0) cout << ' ';
        }
    } else {
        cout << 1 << nl;
        for (i = 0; i < n; i++) cout << s[i];
    }

    return 0;
}