#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    k = 1;
    for (i = 0; i < n; i++) {
        if (k >= n) k = 0;
        b[k] = a[i];
        k += 2;
    }

    res = 0;
    for (i = 1; i < n - 1; i++) {
        if (b[i] < b[i - 1] && b[i] < b[i + 1]) res++;
    }

    cout << res << nl;
    for (i = 0; i < n; i++) cout << b[i] << ' ';
    cout << nl;

    return 0;
}