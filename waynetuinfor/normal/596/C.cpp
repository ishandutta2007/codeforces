#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int w[maxn], ans[maxn], mx[maxn], anss[maxn];
vector<int> ind[maxn << 1], pi[maxn << 1];
pair<int, int> p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        pi[p[i].second - p[i].first + maxn].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        ind[w[i] + maxn].push_back(i);
    }
    for (int i = 0; i < maxn * 2; ++i) if (ind[i].size()) {
        if (pi[i].size() != ind[i].size()) return cout << "NO" << endl, 0;
        sort(pi[i].begin(), pi[i].end(), [](const int& a, const int& b) {
            return p[a] < p[b];
        });
        for (int j = 0; j < ind[i].size(); ++j) ans[ind[i][j]] = pi[i][j], anss[pi[i][j]] = ind[i][j];
    }
    // vector<pair<int, int>> ps(p, p + n);
    vector<pair<pair<int, int>, int>> vec;
    for (int i = 0; i < n; ++i) vec.push_back(make_pair(p[i], i));
    sort(vec.begin(), vec.end());
    int cur = 0;
    for (int i = 0; i < maxn; ++i) {
        int ind = cur; while (ind < vec.size() && vec[ind].first.first == i) ++ind;
        // if (ind > cur) cout << "ind = " << ind << " cur = " << cur << endl;
        for (int j = cur; j < ind; ++j) {
            mx[vec[j].first.second] = max(mx[vec[j].first.second], mx[vec[j].first.second - 1]);
            if (anss[vec[j].second] < mx[vec[j].first.second]) return cout << "NO" << endl, 0;
            mx[vec[j].first.second] = max(mx[vec[j].first.second], anss[vec[j].second]);
        }
        cur = ind;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << p[ans[i]].first << ' ' << p[ans[i]].second << endl;
    return 0;

}