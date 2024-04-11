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
#define maxe 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll er[maxe], l, r, e, st, f[maxe];
vector<ll> rdj;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 1; i < maxe; i++) er[i] = i;
    for (i = 2; i < maxe; i++) {
        if (er[i] != i) continue;
        for (j = 2 * i; j < maxe; j += i) er[j] = i;
    }

    cin >> t;
    while (t--) {
        cin >> n >> e; res = 0;

        for (i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) a[i] = 0;
            else if (er[a[i]] == a[i]) a[i] = 1;
            else a[i] = 2;
        }

        for (st = 1; st <= e; st++) {
            for (i = st; i <= n; i += e) {
                if (i != st) a[i] += a[i - e];
                if (a[i] - 1 >= 0) res += f[a[i] - 1];
                if (i != st) f[a[i - e]]++;
                else f[0]++;
                // cout << "st, i, res =" _ st _ i _ res << nl;
            }

            for (i = 0; i <= 2 * (n / e + 10); i++) f[i] = 0;
        }

        /* for (i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << nl; */

        cout << res << nl;
    }

    return 0;
}