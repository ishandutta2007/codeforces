// 1158D
// Winding polygonal line

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF 1000000007
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, z;
bool visited[maxn];
vector<array<ll, 2>> p;
string s;

ll cpd(ll a, ll b, ll c) {
    array<ll, 2> x = {p[b][0] - p[a][0], p[b][1] - p[a][1]};
    array<ll, 2> y = {p[c][0] - p[b][0], p[c][1] - p[b][1]};
    // cout << a << ' ' << b << ' ' << c << ' ' << x[0] * y[1] - x[1] * y[0] << nl;
    return x[0] * y[1] - x[1] * y[0];
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; p.pb({-INF, -INF});
    for (i = 0; i < n; i++) {
        cin >> a >> b; p.pb({a, b});
    }
    cin >> s; s = "#L" + s;

    for (i = 1; i <= n; i++) {
        z = 1 - 2 * (s[i] == 'L'); k = 0;
        for (j = 1; j <= n; j++) {
            if (visited[j]) continue;
            if (k == 0) {
                k = j; continue;
            }
            if (z * (cpd(j, m, k)) > 0) k = j;
        }
        m = k; visited[m] = true; cout << m << ' ';
    }

    return 0;
}