#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
pair<pair<int, int>, int> p[maxn];
int ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;
    }
    sort(p, p + m, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) { return a.first.first == b.first.first ? a.first.second < b.first.second : a.first.first < b.first.first; });
    for (int i = 0; i < m; ) {
        int ind = i;
        while (ind < m && p[ind].first.first == p[i].first.first) ++ind;
        if (ind - i > 2) {
            ++ans[p[i].second]; ++ans[p[ind - 1].second];
            for (int j = i + 1; j < ind - 1; ++j) ans[p[j].second] += 2;
        } 
        if (ind - i == 2) ++ans[p[i].second], ++ans[p[ind - 1].second];
        i = ind;
    } 
    sort(p, p + m, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) { return a.first.second == b.first.second ? a.first.first < b.first.first : a.first.second < b.first.second; });
    for (int i = 0; i < m; ) {
        int ind = i;
        while (ind < m && p[ind].first.second == p[i].first.second) ++ind;
        if (ind - i > 2) {
            ++ans[p[i].second]; ++ans[p[ind - 1].second];
            for (int j = i + 1; j < ind - 1; ++j) ans[p[j].second] += 2;
        } 
        if (ind - i == 2) ++ans[p[i].second], ++ans[p[ind - 1].second];
        i = ind;
    }
    sort(p, p + m, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        int da = a.first.first - a.first.second, db = b.first.first - b.first.second;
        if (da != db) return da < db;
        return a.first.first < b.first.first;
    });
    for (int i = 0; i < m; ) {
        int ind = i;
        vector<pair<pair<int, int>, int>> vec; 
        while (ind < m && p[ind].first.first - p[ind].first.second == p[i].first.first - p[i].first.second) ++ind;
        if (ind - i > 2) {
            ++ans[p[i].second]; ++ans[p[ind - 1].second];
            for (int j = i + 1; j < ind - 1; ++j) ans[p[j].second] += 2;
        } 
        if (ind - i == 2) ++ans[p[i].second], ++ans[p[ind - 1].second];
        i = ind;
    }
    sort(p, p + m, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        int da = a.first.first + a.first.second, db = b.first.first + b.first.second;
        if (da != db) return da < db;
        return a.first.first < b.first.first;
    });

    for (int i = 0; i < m; ) {
        int ind = i;
        vector<pair<pair<int, int>, int>> vec; 
        while (ind < m && p[ind].first.first + p[ind].first.second == p[i].first.first + p[i].first.second) ++ind;
        if (ind - i > 2) {
            ++ans[p[i].second]; ++ans[p[ind - 1].second];
            for (int j = i + 1; j < ind - 1; ++j) ans[p[j].second] += 2;
        } 
        if (ind - i == 2) ++ans[p[i].second], ++ans[p[ind - 1].second];
        i = ind;
    }
    vector<int> vec(10, 0);
    for (int i = 0; i < m; ++i) ++vec[ans[i]];
    for (int i = 0; i <= 8; ++i) cout << vec[i] << ' '; cout << endl;
    return 0;
}