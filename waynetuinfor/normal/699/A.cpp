#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
pair<int, char> p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i].second;
    for (int i = 0; i < n; ++i) cin >> p[i].first;
    int ans = INT_MAX;
    for (int i = 0; i < n - 1; ++i) {
        if (p[i].second == 'R' && p[i + 1].second == 'L') ans = min(ans, (p[i + 1].first - p[i].first) / 2);
    }
    if (ans == INT_MAX) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}