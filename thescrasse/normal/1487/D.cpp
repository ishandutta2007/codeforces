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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, bsl, bsm, bsu;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        bsl = 0; bsu = 1000000000;
        while (bsl != bsu) {
            bsm = (bsl + bsu + 1) / 2;
            if (2 * bsm * bsm + 2 * bsm + 1 <= n) bsl = bsm;
            else bsu = bsm - 1;
        }

        cout << bsl << nl;
    }

    return 0;
}