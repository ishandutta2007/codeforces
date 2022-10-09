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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, ty, p, x, q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) k++;
    }

    while (q--) {
        cin >> ty;
        if (ty == 1) {
            cin >> p;
            if (a[p] == 0) k--;
            else k++;
            a[p] ^= 1;
        } else {
            cin >> x; x = n - x + 1;
            if (x > k) cout << 1 << nl;
            else cout << 0 << nl;
        }
    }

    return 0;
}