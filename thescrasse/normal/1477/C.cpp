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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x[maxn], y[maxn];
bool visited[maxn];
array<ll, 2> o;

ll dist(ll a, ll b) {
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    k = 1; m = n;
    while (m--) {
        cout << k << ' ';
        visited[k] = true;
        o = {-1, -1};
        for (i = 1; i <= n; i++) {
            if (visited[i]) continue;
            o = max(o, {dist(i, k), i});
        }

        k = o[1];
    }

    return 0;
}