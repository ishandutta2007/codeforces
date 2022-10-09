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
array<ll, 2> mn, mx;

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
        mn = {INF, 0}; mx = {-INF, 0};
        for (i = 1; i <= n; i++) {
            cin >> a; mn = min(mn, {a, i}); mx = max(mx, {a, i});
        }
        cout << mn[1] _ mx[1] << nl;
    }

    return 0;
}