#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], f[maxn];
map<ll, ll> dc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> f[i];
        if (dc[f[i]] == 0) dc[f[i]] = i + 1;
        else dc[f[i]] = -1;
    }

    for (i = 0; i < m; i++) {
        cin >> b[i];
    }

    flag[0] = 0;
    for (i = 0; i < m; i++) {
        if (dc[b[i]] == 0) flag[0] = 2;
        else if (dc[b[i]] == -1) flag[0] = max(flag[0], (ll)1);
        else a[i] = dc[b[i]];
    }

    if (flag[0] == 2) cout << "Impossible";
    else if (flag[0] == 1) cout << "Ambiguity";

    if (flag[0] == 0) {
        cout << "Possible" << nl;
        for (i = 0; i < m; i++) cout << a[i] << ' ';
    }

    return 0;
}