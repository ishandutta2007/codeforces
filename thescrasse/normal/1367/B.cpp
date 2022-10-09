#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 50

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; flag[0] = 0; flag[1] = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            if ((i + a[i]) % 2 == 1) {
                flag[i % 2]++;
            }
        }
        if (flag[0] != flag[1]) cout << -1 << nl;
        else cout << flag[0] << nl;
    }

    return 0;
}