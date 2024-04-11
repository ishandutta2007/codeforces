#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> idx(3);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        idx[A % 3].emplace_back(i);
    }

    for (int mask1 = 0; mask1 < 8; mask1++) {
        for (int mask2 = 0; mask2 < 8; mask2++) {
            vector<bool> appeared(3, false);
            for (int i = 0; i < 3; i++) {
                if (!(mask1 >> i & 1))
                    continue;
                for (int j = 0; j < 3; j++) {
                    if (!(mask2 >> j & 1))
                        continue;
                    int val = ((i + j) * (i + j) + i * j) % 3;
                    appeared[val] = true;
                }
            }
            int Z = -1;
            for (int i = 0; i < 3; i++) {
                int x = (mask1 >> i & 1), y = (mask2 >> i & 1);
                if (!idx[i].empty() and x == 0 and y == 0) {
                    Z = -1;
                    break;
                }
                if (!appeared[i])
                    Z = i;
            }
            if (Z == -1)
                continue;
            int Min = 0, Max = 0;
            for (int i = 0; i < 3; i++) {
                int x = (mask1 >> i & 1), y = (mask2 >> i & 1);
                int sz = (int)idx[i].size();
                if (x and !y)
                    Min += sz, Max += sz;
                if (x and y) {
                    Min += 0;
                    Max += sz;
                }
            }
            if (!(Min <= N / 2 and N / 2 <= Max))
                continue;
            string ans(N, '0');
            int cur = 0;
            for (int i = 0; i < 3; i++) {
                int x = (mask1 >> i & 1), y = (mask2 >> i & 1);
                if (x and !y) {
                    for (int &pos : idx[i]) {
                        ans[pos] = '1';
                        cur++;
                    }
                }
            }
            for (int i = 0; i < 3; i++) {
                int x = (mask1 >> i & 1), y = (mask2 >> i & 1);
                if (x and y) {
                    for (int &pos : idx[i]) {
                        if (cur < N / 2) {
                            ans[pos] = '1';
                            cur++;
                        }
                    }
                }
            }
            cout << Z << "\n";
            cout << ans << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}