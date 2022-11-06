#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int c[maxn], t[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) cin >> c[i], vec.push_back(make_pair(c[i], i));
    sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
    set<int> s;
    for (int i = k + 1; i <= k + n; ++i) s.insert(i);
    long long ans = 0;
    for (auto i : vec) {
        auto it = s.lower_bound(i.second);
        t[i.second] = *it;
        s.erase(it);
        ans += (long long)i.first * (t[i.second] - i.second);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) cout << t[i] << ' '; cout << endl;
    return 0;
}