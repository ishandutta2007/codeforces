#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 0; i <= k; i++) b[i] = 0;
    for (i = 0; i < n; i++) {
        cin >> a[i]; b[a[i] % k]++;
    }

    res = 0;
    for (i = 1; i <= (k - 1) / 2; i++) {
        res += min(b[i], b[k - i]);
    }
    if (k % 2 == 0) res += b[k / 2] / 2;
    res += b[0] / 2; res *= 2;

    cout << res;

    return 0;
}