#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v.emplace_back(a + b + c + d, -i);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int ans = -1;
    for (int i = 0; i < n; ++i) if (v[i].second == 0) ans = i + 1;
    cout << ans << endl;
}