#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], l, p[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < m; i++) {
        cin >> b[i];
    }

    l = m - 1;
    for (i = n - 1; i >= 0; i--) {
        if (l >= 0 && a[i] == b[l]) l--;
        p[i] = l + 1;
    }
    if (l != -1) {
        cout << 0; return 0;
    }

    flag[0] = 1;
    for (i = n - 1; i >= 0; i--) {
        if (a[i] < b[max((ll)0, p[i] - 1)]) flag[0] = 0;
    }

    if (flag[0] == 0) {
        cout << 0; return 0;
    }

    l = m - 1; res = 1; k = 1; flag[0] = 0;
    for (i = n - 1; i >= 0; i--) {
        if (l >= 0 && a[i] == b[l]) {
            l--; res *= k; res %= mod; k = 1; flag[0] = 1;
        } else if (l + 1 < m && a[i] < b[l + 1]) {
            flag[0] = 0;
        } else if (flag[0] == 1) {
            k++;
        }
    }

    cout << res;

    return 0;
}