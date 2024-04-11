#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int L = 500000, K = 20;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* -----  ----- */
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, int>> segs(N);
    for (auto& s : segs) cin >> s.first >> s.second;

    /* ----- xr ----- */
    sort(segs.begin(), segs.end());
    vector<vector<int>> to(K + 1, vector<int>(L + 1));

    int itr = 0, y = 0;  // r
    for (int x = 0; x <= L; ++x) {
        // 
        while (itr < N && segs[itr].first <= x) {
            y = max(y, segs[itr].second);
            ++itr;
        }
        to[0][x] = max(x, y);
    }

    /* -----  ----- */
    for (int k = 1; k <= K; ++k) {
        for (int x = 0; x <= L; ++x) {
            to[k][x] = to[k - 1][to[k - 1][x]];
        }
    }

    /* -----  ----- */
    for (int q = 0; q < Q; ++q) {
        int x, y;
        cin >> x >> y;

        int ans = 0;
        while (x < y) {
            if (to[0][x] == x) {  // x
                ans = -1;
                break;
            }

            int k;  // y
            for (k = K; k >= 0; --k) {
                if (to[k][x] < y) break;
            }

            if (k < 0) {  // 1()
                ans += 1;
                x = to[0][x];
            } else {
                ans += (1 << k);  // 2^k
                x = to[k][x];
            }
        }

        cout << ans << "\n";
    }
    return 0;
}