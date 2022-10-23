#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxx 500010

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n + 1, 0);
    vector<ll> f(maxx, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i]; f[a[i]]++;
    }

    ll flag = 1;
    for (ll i = 1; i < x; i++) {
        if (f[i] % (i + 1) != 0) {
            flag = 0; cout << "No" << nl; break;
        }
        f[i + 1] += (f[i] / (i + 1));
    }

    if (flag == 1) cout << "Yes" << nl;

    return 0;
}