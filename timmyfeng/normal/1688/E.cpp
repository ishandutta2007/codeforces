#include <bits/stdc++.h>
using namespace std;

int n, m;

int query(vector<int> indices) {
    string s(m, '0');
    for (auto i : indices) s[i] = '1';
    cout << "? " << s << endl;
    int result;
    cin >> result;
    return result;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        edges.push_back({query({i}), i});
    }
    sort(edges.begin(), edges.end());

    int ans = 0;
    vector<int> tree;
    for (auto [w, i] : edges) {
        tree.push_back(i);
        if (query(tree) < ans + w) {
            tree.pop_back();
        } else ans += w;
    }

    cout << "! " << ans << endl;
}