#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10];
ll a[10] = {1, 1, 2, 3, 2, 4, 3, 5, 4, 8};

ll solve(ll n) {
    ll res = 0;
    while (n > 0) {
        if (n <= 10) {
            res += a[n - 1]; break;
        } else if (n % 4 == 2) {
            n /= 2; res += n; n--;
        } else {
            n -= 2; res++;
        }
    }

    return res;
}

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
        if (n <= 10) res = a[n - 1];
        else if (n % 2 == 0) res = solve(n);
        else res = n - solve(n - 1);

        cout << res << nl;
    }

    return 0;
}