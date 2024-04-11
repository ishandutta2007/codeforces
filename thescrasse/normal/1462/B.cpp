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
        cin >> n >> s; flag[0] = 0;
        if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') flag[0] = 1;
        if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') flag[0] = 1;
        if (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') flag[0] = 1;
        if (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') flag[0] = 1;
        if (s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') flag[0] = 1;

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}