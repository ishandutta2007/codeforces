#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
pair<int, int> p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; 
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p, p + n, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int r = -1, ans = 0;
    for (auto i : p) {
        if (i.first > r) {
            ++ans; r = i.second;
        }
    }
    cout << ans << endl;
    return 0;
}