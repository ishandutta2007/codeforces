#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
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
        cin >> n >> s; s = '#' + s; a[0] = 3;
        for (i = 1; i <= n; i++) {
            if (s[i] == '1') {
                if (a[i - 1] == 2) {
                    a[i] = 1; b[i] = 0;
                } else {
                    a[i] = 2; b[i] = 1;
                }
            } else {
                if (a[i - 1] == 1) {
                    a[i] = 0; b[i] = 0;
                } else {
                    a[i] = 1; b[i] = 1;
                }
            }
        }

        for (i = 1; i <= n; i++) cout << b[i];
        cout << nl;
    }

    return 0;
}