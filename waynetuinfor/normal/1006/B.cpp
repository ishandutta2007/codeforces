#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.emplace_back(x, i);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    vector<int> ans;
    int s = 0;
    for (int i = 0; i < k; ++i) ans.push_back(v[i].second), s += v[i].first;
    sort(ans.begin(), ans.end());
    int last = -1;
    cout << s << endl;
    for (int i = 0; i < ans.size(); ++i) {
        int x = i == ans.size() - 1 ? n - 1 : ans[i];
        cout << x - last << ' ';
        last = x;
    }
    cout << endl;
}