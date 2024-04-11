#include <bits/stdc++.h>
using namespace std;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> l(n), r(n);

    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    vector<tuple<long long, bool, int>> events;

    for (int i = 1; i < n; ++i) {
        events.push_back({l[i] - r[i - 1], false, i});
    }

    for (int i = 1; i <= m; ++i) {
        long long a;
        cin >> a;
        events.push_back({a, true, i});
    }

    min_queue<pair<long long, int>> gaps;
    sort(events.begin(), events.end());
    vector<int> ans(n);

    for (auto [x, t, i] : events) {
        if (!t) {
            gaps.push({r[i] - l[i - 1], i});
        } else {
            if (!gaps.empty() && gaps.top().first >= x) {
                auto [y, j] = gaps.top();
                gaps.pop();
                ans[j] = i;
            }
        }
    }

    if (!gaps.empty()) {
        cout << "No\n";
        exit(0);
    }

    cout << "Yes\n";
    for (int i = 1; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}