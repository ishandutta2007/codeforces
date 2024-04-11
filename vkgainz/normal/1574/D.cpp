#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
 
using namespace std;
 
vector<vector<int>> a;
 
int cost(vector<int> x) {
    int ans = 0;
    for (int i = 0; i < (int) x.size(); i++) {
        ans += a[i][x[i]];
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<vector<int>> banned;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        vector<int> b(n);
        for (int j = 0; j < n; j++) {
            cin >> b[j];
            --b[j];
        }
        banned.insert(b);
    }
    set<pair<int, vector<int>>> in;
    vector<int> v;
    int s = 0;
    for (int i = 0; i < n; i++) {
        v.push_back(a[i].size() - 1);
        s += a[i].back();
    }
    in.insert({-s, v});
    vector<int> ans;
    while (!in.empty()) {
        auto x = *in.begin();
        if (not banned.count(x.second)) {
            ans = x.second;
            break;
        }
        in.erase(in.begin());
        for (int j = 0; j < n; j++) {
            if (x.second[j] == 0) continue;
            int new_sum = -x.first - a[j][x.second[j]] + a[j][x.second[j] - 1];
            --x.second[j];
            in.insert({-new_sum, x.second});
            ++x.second[j];

        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
}