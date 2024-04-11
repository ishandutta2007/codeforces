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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll x = 0, y = 0;
        for (ll i = 1; i <= n; i++) {
            ll a; cin >> a;
            if (a % 2) y++;
            else x++;
        }

        x %= 2; y %= 4;

        if (y == 0 || y == 3) cout << "Alice" << nl;
        else if (x == 1 && y == 1) cout << "Alice" << nl;
        else cout << "Bob" << nl;
    }

    return 0;
}