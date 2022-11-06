#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
int d[maxn][maxn], x[maxn];
bool ok[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> d[i][j];
    }
    vector<long long> opt;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int k = n; k > 0; --k) {
        ok[x[k]] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) d[i][j] = min(d[i][j], d[i][x[k]] + d[x[k]][j]);
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) if (ok[i]) {
            for (int j = 1; j <= n; ++j) if (ok[j]) ans += d[i][j];
        }
        opt.push_back(ans);
    }
    reverse(opt.begin(), opt.end());
    for (long long dis : opt) cout << dis << ' '; cout << endl;
    return 0;
}