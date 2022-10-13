#include <bits/stdc++.h>
using namespace std;

int pre[1 << 8], curr[1 << 8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k; cin >> n >> m >> k;
    vector<int> L(n), R(n);
    vector<pair<int, int>> events(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        events[2 * i] = {L[i], n + i};
        events[2 * i + 1] = {R[i] + 1, i};
    }
    sort(events.begin(), events.end());
    vector<int> idx(n);
    int curr_msk = 0;
    for (int i = 0; i < 2 * n; i++) {
        int curr_idx = events[i].second % n;
        bool st = false;
        if (events[i].second >= n) {
            for (int j = 0; j < k; j++) {
                if (curr_msk & (1 << j)) continue;
                idx[curr_idx] = j;
                break;
            }
            st = true;
        }
        for (int msk = 0; msk < (1 << k); msk++) {
            int cover_msk = msk & curr_msk;
            int add = (events[i].first);
            if (i > 0) add -= events[i - 1].first;
            add *= (__builtin_popcount(cover_msk) % 2);
            if (st) {
                curr[msk] = max(pre[msk ^ (1 << idx[curr_idx])], pre[msk]) + add;
            }
            else {
                curr[msk] = pre[msk] + add;
            }
        }
        curr_msk ^= (1 << idx[curr_idx]);
        if (events[i].second < n) {
        }
        for (int msk = 0; msk < (1 << k); msk++)
            pre[msk] = curr[msk], curr[msk] = 0;
    }
    cout << *max_element(pre, pre + (1 << k));
}