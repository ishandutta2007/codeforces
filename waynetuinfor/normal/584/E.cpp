#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
int p[maxn], pos[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) {
        int s; cin >> s; pos[s] = i;
    }
    int ans = 0;
    vector<pair<int, int>> sw;
    for (int i = 1; i <= n; ++i) ans += abs(pos[p[i]] - i);
    ans /= 2;
    for (int i = 1; i <= n; ++i) {
        int now = i;
        for (int j = i - 1; j >= 1 && pos[p[now]] < now; --j) {
            if (pos[p[j]] > j) {
                sw.emplace_back(now, j);
                swap(p[now], p[j]);
                now = j;
            }
        }
    }
    cout << ans << '\n';
    cout << sw.size() << '\n';
    for (auto i : sw) cout << i.first << ' ' << i.second << '\n';
    return 0;
}