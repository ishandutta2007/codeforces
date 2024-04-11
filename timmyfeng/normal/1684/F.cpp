#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    vector<pair<int, int>> segments(m);
    for (auto &[l, r] : segments) cin >> l >> r, --l, --r;


    int answer_l = n, answer_r = -1;

    sort(segments.rbegin(), segments.rend());
    map<int, int> prev;
    int min_second = n;

    for (int i = n - 1, j = 0; i >= 0; --i) {
        if (prev.count(a[i])) min_second = min(min_second, prev[a[i]]);
        prev[a[i]] = i;

        while (j < m && segments[j].first == i) {
            auto [l, r] = segments[j++];
            if (min_second <= r) {
                answer_l = min(answer_l, min_second);
            }
        }
    }

    sort(segments.begin(), segments.end(), [&](auto a, auto b) { return a.second < b.second; });
    prev.clear();
    int max_second = -1;

    for (int i = 0, j = 0; i < n; ++i) {
        if (prev.count(a[i])) max_second = max(max_second, prev[a[i]]);
        prev[a[i]] = i;

        while (j < m && segments[j].second == i) {
            auto [l, r] = segments[j++];
            if (max_second >= l) {
                answer_r = max(answer_r, max_second);
            }
        }
    }

    if (answer_l == n) {
        cout << 0 << "\n";
        return;
    }

    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
    }

    vector<pair<int, int>> ranges;
    for (auto [x, indices] : pos) {
        int l = 0, r = (int) indices.size() - 1;
        while (l + 1 < (int) indices.size() && indices[l + 1] < answer_l) ++l;
        while (r - 1 >= 0 && indices[r - 1] > answer_r) --r;

        if (indices[l] < answer_l && answer_r < indices[r]) {
            ranges.push_back({indices[l], indices[r]});
        }
    }

    sort(segments.begin(), segments.end());
    sort(ranges.begin(), ranges.end());

    int ptr = 0, last = 0;
    vector<pair<int, int>> requirements;
    for (auto [l, r] : ranges) {
        while (ptr < m && segments[ptr].first <= l) {
            last = max(last, segments[ptr++].second);
        }
        if (last >= r) {
            requirements.push_back({l, r});
        }
    }

    int answer = n;
    sort(requirements.begin(), requirements.end());
    for (auto [l, r] : requirements) {
        answer = min(answer, answer_r - l + 1);
        answer_r = max(answer_r, r);
    }
    answer = min(answer, answer_r - answer_l + 1);

    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}