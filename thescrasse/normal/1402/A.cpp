#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], b, cr, x, s;
array<ll, 2> a[maxn];
priority_queue<ll> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) a[i] = {0, 0};
    for (j = 0; j < 2; j++) {
        for (i = 0; i < n; i++) {
            cin >> a[i][j];
        }
    }

    sort(a, a + n);

    res = 0; i = 0;

    while (true) {
        if (pq.empty()) {
            if (i >= n) break;
            else cr = a[i][0];
        }
        while (i < n && a[i][0] == cr) {
            pq.push(a[i][1]); s += a[i][1]; i++;
        }
        x = pq.top(); pq.pop(); s -= x;
        res += s; cr++;
    }

    cout << res;

    return 0;
}