#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 210000;

vector <pii> g[N], h[N];

int main () {
    int n, m, l, r;
    cin >> n >> m;
    int res = 1e9;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &l, &r);
        res = min (res, r - l + 1);
    }
    cout << res << endl;
    for (int i = 1, j = 0; i <= n; i++, j++, j %= res) printf ("%d ", j);
}