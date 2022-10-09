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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, pp[maxn], sp[maxn];
vector<ll> rs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; pp[0] = 1; sp[n] = 1;
    for (i = 1; i <= n - 1; i++) {
        if (gcd(i, n) == 1) pp[i] = (i * pp[i - 1]) % n;
        else pp[i] = pp[i - 1];
    }
    for (i = n - 1; i >= 1; i--) {
        if (gcd(i, n) == 1) sp[i] = (i * sp[i - 1]) % n;
        else sp[i] = sp[i - 1];
    }

    if (pp[n - 1] == 1) {
        for (i = 1; i <= n - 1; i++) {
            if (gcd(i, n) == 1) rs.pb(i);
        }
    } else {
        for (i = 0; i <= n - 2; i++) {
            if ((pp[i] * sp[i + 2]) % n == 1) {
                for (j = 1; j <= n - 1; j++) {
                    if (j != i + 1 && gcd(j, n) == 1) rs.pb(j);
                }
                break;
            }
        }
    }

    cout << rs.size() << nl;
    for (auto u : rs) cout << u << ' ';
    cout << nl;

    return 0;
}