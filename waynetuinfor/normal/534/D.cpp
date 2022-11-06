#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
set<pair<int, int>> s[3];
int ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s[x % 3].insert(make_pair(x, i + 1));
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        pair<int, int> p;
        auto it = s[cur % 3].lower_bound(make_pair(cur, 0));
        if (it != s[cur % 3].end() && it->first == cur) {
            p = *it;
        } else {
            if (it == s[cur % 3].begin()) return cout << "Impossible\n", 0;
            --it;
            p = *it;
        }
        s[cur % 3].erase(p);
        cur = p.first + 1;
        ans[i] = p.second;
    }
    cout << "Possible\n";
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}