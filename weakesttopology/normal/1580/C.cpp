#include <bits/stdc++.h>
using namespace std;
constexpr int magic = 450;
int small[magic][magic];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> x(N), y(N), sum(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
        sum[i] = x[i] + y[i];
    }
    vector<int> add(M);
    auto update = [&](int i, int j, int value) {
        while (j < M) {
            j += x[i];
            if (j < M) add[j] += value;
            j += y[i];
            if (j < M) add[j] -= value;
        }
    };
    vector<int> last(N);
    int big = 0;
    for (int j = 0; j < M; ++j) {
        int op, k;
        cin >> op >> k;
        --k;
        int value = op == 1 ? +1 : -1;
        if (op == 1) {
            last[k] = j;
        }
        big += add[j];
        if (sum[k] >= magic) {
            update(k, last[k], value);
            if (op == 2 && (j - last[k]) % sum[k] >= x[k]) {
                --big;
            }
        } else {
            int s = (last[k] + x[k]) % sum[k];
            for (int c = 0; c < y[k]; ++c) {
                small[s][sum[k]] += value;
                ++s;
                if (s == sum[k]) s = 0;
            }
        }
        int ans = big;
        for (int mod = 1; mod < magic; ++mod) {
            ans += small[j % mod][mod];
        }
        cout << ans << '\n';
    }
    exit(0);
}