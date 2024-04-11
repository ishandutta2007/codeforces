#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    long long ans = numeric_limits<long long>::min();
    auto solve = [&](auto &self, int l, int r) -> vector<long long> {
        if (r <= l) {
            return {0};
        } else {
            int m = int(min_element(a.begin() + l, a.begin() + r) - a.begin());
            auto left = self(self, l, m), right = self(self, m + 1, r);
            int K = (int)left.size(), L = (int)right.size();
            vector<long long> res(K + L, numeric_limits<long long>::min());
            for (int i = 0; i < K; ++i) {
                for (int j = 0; j < L; ++j) {
                    for (int t : {0, 1}) {
                        res[i + j + t] = max(res[i + j + t], left[i] + right[j] - 2LL * i * j * a[m] + t * (M - (1 + 2 * (i + j))) * a[m]);
                    }
                }
            }
            return res;
        }
    };
    auto res = solve(solve, 0, N);
    cout << res[M] << '\n'; 
    exit(0);
}