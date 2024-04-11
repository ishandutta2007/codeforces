#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

long long height[N], rate[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    long long p;
    cin >> n >> m >> k >> p;

    for (int i = 0; i < n; ++i) {
        cin >> height[i] >> rate[i];
    }

    long long l = 0, r = (long long) N * N * N;
    while (l < r) {
        long long s = (l + r) / 2;

        priority_queue<array<long long, 3>> que;
        for (int i = 0; i < n; ++i) {
            if (s < height[i] + m * rate[i]) {
                que.push({-s / rate[i], s, i});
            }
        }

        bool ok = true;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j) {
                if (!que.empty()) {
                    auto [x, y, id] = que.top();
                    ok &= -x > i;
                    que.pop();

                    if (y + p < height[id] + m * rate[id]) {
                        que.push({-(y + p) / rate[id], y + p, id});
                    }
                }
            }
        }
        ok &= que.empty();

        if (ok) {
            r = s;
        } else {
            l = s + 1;
        }
    }

    cout << l << "\n";
}