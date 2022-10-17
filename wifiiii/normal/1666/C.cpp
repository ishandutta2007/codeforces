#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<pair<int,int>> a(3);
    for(auto &[x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end());
    vector<array<int,4>> ans;
    if(a[0].first != a[1].first) {
        ans.push_back({a[0].first, a[0].second, a[1].first, a[0].second});
    }
    if(a[2].first != a[1].first) {
        ans.push_back({a[2].first, a[2].second, a[1].first, a[2].second});
    }
    auto [l, r] = minmax({a[0].second, a[1].second, a[2].second});
    if(l != r) ans.push_back({a[1].first, l, a[1].first, r});
    cout << ans.size() << '\n';
    for(auto [a, b, c, d] : ans) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
}