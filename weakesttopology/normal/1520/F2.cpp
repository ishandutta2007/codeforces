#include <bits/stdc++.h>
int query(int l, int r) {
    std::cout << "? " << l << ' ' << r << std::endl;
    int res;
    std::cin >> res;
    if (res == -1) exit(0);
    return r - l + 1 - res; // number of zeros
}
const int magic = 32;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, T;
    std::cin >> N >> T;
    std::vector<int> cnt;
    for (int t = 0; t < T; ++t) {
        int k;
        std::cin >> k;
        if (t == 0) {
            for (int i = 1; i <= N; i += magic) {
                int r = std::min(N, i + magic - 1);
                cnt.push_back(query(1, r));
            }
        }
        auto iter = std::lower_bound(cnt.begin(), cnt.end(), k);
        int L = (iter - cnt.begin()) * magic;
        int R = std::min(L + magic, N);
        while (L + 1 < R) {
            int M = (L + R) / 2;
            query(1, M) < k ? L = M : R = M;
        }
        while (iter != cnt.end()) {
            *iter -= 1;
            ++iter;
        }
        std::cout << "! " << R << std::endl;
    }
    exit(0);
}