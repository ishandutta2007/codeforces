#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int h[maxn], n, m, d[maxn];

int bs(int, int);
bool check(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    int Min = (int)1e8 + 1;
    for (int i = 0; i < m; ++i) cin >> d[i] >> h[i], Min = min(Min, h[i]);
    for (int i = 0; i < m - 1; ++i) if (abs(h[i + 1] - h[i]) > d[i + 1] - d[i]) return cout << "IMPOSSIBLE\n", 0;
    int ans = bs(Min, 2 * (int)1e9 + 1); 
    if (!check(ans)) return cout << "IMPOSSIBLE\n", 0;
    cout << ans << '\n';
}

bool check(int Max) {
    if (abs(Max - h[0]) <= d[0] - 1) return true;
    for (int i = 0; i < m - 1; ++i) {
        if (abs(Max - h[i]) + abs(Max - h[i + 1]) <= d[i + 1] - d[i]) return true;
    }
    if (abs(Max - h[m - 1]) <= n - d[m - 1]) return true;
    return false;
}

int bs(int l, int r) {
    if (r - l == 1) return l;
    int m = l + r >> 1;
    if (check(m)) return bs(m, r);
    return bs(l, m);
}