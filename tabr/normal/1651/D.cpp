#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        st.emplace(a[i]);
    }
    vector<pair<int, int>> b;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    for (int i = 0; i < n; i++) {
        for (int dir = 0; dir < 4; dir++) {
            int x = a[i].first + dx[dir];
            int y = a[i].second + dy[dir];
            if (st.count(make_pair(x, y))) {
                continue;
            }
            b.emplace_back(x, y);
        }
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    map<pair<int, int>, pair<int, int>> mp;
    queue<pair<int, int>> que;
    for (auto p : b) {
        mp[p] = p;
        que.emplace(p);
    }
    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (mp.count(make_pair(nx, ny))) {
                continue;
            }
            if (!st.count(make_pair(nx, ny))) {
                continue;
            }
            mp[make_pair(nx, ny)] = mp[make_pair(x, y)];
            que.emplace(nx, ny);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mp[a[i]].first << " " << mp[a[i]].second << '\n';
    }
    return 0;
}