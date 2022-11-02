#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int N;
        cin >> N;

        vector<pair<int, int>> segs(N);
        for (auto& seg : segs) {
            cin >> seg.first >> seg.second;
        }

        vector<int> idx(N);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return segs[a] < segs[b]; });

        vector<int> ans(N);
        int g = 1, l = segs[idx[0]].second;
        bool judge = false;

        for (int i : idx) {
            if (segs[i].first > l) {
                judge = true;
                g = 3 - g;
            }
            ans[i] = g;
            l = max(l, segs[i].second);
        }

        if (!judge) {
            cout << -1;
        } else {
            for (int g : ans) {
                cout << g << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}