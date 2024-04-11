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
bitset<1120> kn;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    kn[0] = 1;
    for (i = 1; i <= 1111; i++) kn |= (kn << 11);
    for (i = 1; i <= 1111; i++) kn |= (kn << 111);

    cin >> t;
    while (t--) {
        cin >> n;
        if (n >= 1111) {
            cout << "YES" << nl;
        } else if (kn[n] == 1) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}