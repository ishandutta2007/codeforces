#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], c[maxn];
set<ll> s1, s2;

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
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++) {
            s1.insert(i); s2.insert(i);
        }
        for (i = 1; i <= n; i++) {
            if (a[i] != a[i - 1]) {
                b[i] = a[i]; c[i] = a[i];
            } else {
                b[i] = *(s1.begin());
                auto it = s2.upper_bound(a[i]); it--;
                c[i] = (*it);
            }
            s1.erase(b[i]); s2.erase(c[i]);
        }

        for (i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << nl;
        for (i = 1; i <= n; i++) cout << c[i] << ' ';
        cout << nl;
    }

    return 0;
}