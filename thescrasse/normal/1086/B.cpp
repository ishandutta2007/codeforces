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

ll i, i1, j, k, k1, t, n, m, flag[10], a, b;
ll dg[maxn], s;
long double res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> s; s *= 2;
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b; dg[a]++; dg[b]++;
    }

    for (i = 1; i <= n; i++) {
        if (dg[i] == 1) k++;
    }

    res = (long double)s / k;
    cout << fixed << setprecision(10);
    cout << res << nl;

    return 0;
}