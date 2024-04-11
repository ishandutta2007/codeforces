#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int N, M;
        cin >> N >> M;

        vector<int> path[N];
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            path[u].push_back(v);
            path[v].push_back(u);
        }

        ll ans = 1;

        int color[N];
        fill(color, color + N, -1);
        bool judge = true;

        for (int r = 0; r < N; ++r) {
            if (color[r] >= 0) continue;

            color[r] = 0;
            int cnt[2] = {1, 0};

            queue<int> que;
            que.push(r);
            while (!que.empty()) {
                int v = que.front();
                que.pop();

                for (int sv : path[v]) {
                    if (color[sv] < 0) {
                        color[sv] = 1 - color[v];
                        ++cnt[color[sv]];
                        que.push(sv);
                    } else {
                        if (color[sv] == color[v]) {
                            judge = false;
                            break;
                        }
                    }
                }

                if (!judge) break;
            }

            if (!judge) break;

            ans *= (mypow(2LL, cnt[0]) + mypow(2LL, cnt[1])) % MOD;
            ans %= MOD;
        }

        cout << (judge ? ans : 0) << endl;
    }
    return 0;
}