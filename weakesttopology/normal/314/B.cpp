#include <bits/stdc++.h>
constexpr int K = 30;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x, y;
    std::cin >> x >> y;
    std::string s, t;
    std::cin >> s >> t;
    int N = s.size(), M = t.size();
    std::vector<std::array<int, K>> go(M);
    std::vector<std::array<int64_t, K>> add(M);
    for (int j = 0; j < M; ++j) {
        int &nj = go[j][0] = j;
        for (int i = 0; i < N; ++i) {
            if (s[i] == t[nj]) {
                nj = (nj + 1) % M;
                add[j][0] += (nj == 0);
            }
        }
    }
    for (int k = 0; k + 1 < K; ++k) {
        for (int j = 0; j < M; ++j) {
            int nj = go[j][k];
            go[j][k + 1] = go[nj][k];
            add[j][k + 1] = add[j][k] + add[nj][k];
        }
    }
    int64_t ans = 0;
    int j = 0;
    for (int k = 0; k < K; ++k) {
        if (x >> k & 1) {
            ans += add[j][k];
            j = go[j][k];
        }
    }
    ans /= y;
    std::cout << ans << '\n';
    exit(0);
}