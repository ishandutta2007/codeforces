#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

array<long long, 3> event[4 * N];
long long l[N], r[N], a[N], b[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int k = 0;

    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        event[k++] = {l[i], 0, i};
        event[k++] = {r[i], 1, i};
    }

    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        event[k++] = {a[i], 2, i};
        event[k++] = {b[i], 3, i};
    }

    array<long long, 3> ans = {0, 0, 0};
    sort(event, event + k);

    map<long long, array<long long, 2>> max_station;
    set<array<long long, 2>> max_video;

    for (int i = 0; i < k; ++i) {
        auto [x, t, j] = event[i];
        if (t == 0) {
            auto it = max_station.lower_bound(r[j]);
            if (it != max_station.end()) {
                ans = max(ans, {(r[j] - l[j]) * it->second[0], j, it->second[1]});
            }
            max_video.insert({r[j], j});
        } else if (t == 1) {
            max_video.erase({r[j], j});
        } else if (t == 2) {
            if (!max_video.empty()) {
                auto it = --max_video.end();
                ans = max(ans, {(min(b[j], it->at(0)) - a[j]) * c[j], it->at(1), j});
            }

            auto it = max_station.lower_bound(b[j]);
            if (it != max_station.end() && it->second[0] >= c[j]) {
                continue;
            }

            while (it != max_station.begin()) {
                auto prv = it;
                if ((--prv)->second[0] > c[j]) {
                    break;
                }
                max_station.erase(prv);
            }

            max_station[b[j]] = {c[j], j};
        }
    }

    for (int i = k - 1; i >= 0; --i) {
        auto [x, t, j] = event[i];
        if (t == 0) {
            max_video.erase({l[j], j});
        } else if (t == 1) {
            max_video.insert({l[j], j});
        } else if (t == 3 && !max_video.empty()) {
            auto it = max_video.begin();
            ans = max(ans, {(b[j] - max(a[j], it->at(0))) * c[j], it->at(1), j});
        }
    }

    cout << ans[0] << "\n";
    if (ans[0] > 0) {
        cout << ans[1] + 1 << " " << ans[2] + 1 << "\n";
    }
}