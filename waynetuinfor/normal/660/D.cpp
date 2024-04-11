#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, inf = 1e9 + 1;
pair<int, int> p[maxn];
map<double, vector<pair<int, int>>> mp;

double cal(int i, int j) {
    int dx = p[i].first - p[j].first, dy = p[i].second - p[j].second;
    if (dy == 0) return inf;
    return (double)dx / (double)dy;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        for (int j = 0; j < i; ++j) {
            double m = cal(i, j);
            mp[m].push_back(make_pair(i, j));
        }
    }
    long long ans = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        vector<pair<int, int>> vec = it->second;
        for (pair<int, int>& a : vec) {
            for (pair<int, int>& b : vec) {
                if (a.first > a.second) swap(a.first, a.second);
                if (b.first > b.second) swap(b.first, b.second);
                if (a.first == b.first || a.second == b.second) continue;
                if (cal(a.first, b.first) == cal(a.second, b.second) || cal(a.first, b.second) == cal(a.second, b.first)) ++ans;
            }
        }
    } 
    cout << ans / 4 << endl;
    return 0;
}