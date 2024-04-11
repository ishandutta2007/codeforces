#include "bits/stdc++.h"
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        auto query = [&]() {
            std::vector<bool> on(N + 1);
            for (auto x : a) {
                if (x <= N) on[x] = true;
            }
            int mex = 0;
            while (on[mex]) ++mex;
            return mex;
        };
        std::vector<int> op;
        auto apply = [&](int i) {
            a[i] = query();
            op.push_back(i);
            //std::cerr << "i == " << i << std::endl;
            //for (int i = 0; i < N; ++i) {
            //    std::cerr << a[i] << ' ';
            //}
            //std::cerr << std::endl;
        };
        std::vector<int> dead(N);
        for (int i = 0; i < N; ++i) {
            if (a[i] == i + 1) {
                dead[i] = true;
            }
        }
        while (std::count(dead.begin(), dead.end(), false)) {
            int mex = query();
            if (mex == 0) {
                int i = std::find(dead.begin(), dead.end(), false) - dead.begin();
                apply(i);
            } else {
                apply(mex - 1);
                dead[mex - 1] = true;
            }
        }
        int K = op.size();
        assert(K <= 2 * N);
        assert(std::is_sorted(a.begin(), a.end()));
        std::cout << K << '\n';
        for (int j = 0; j < K; ++j) {
            std::cout << op[j] + 1 << "\n "[j + 1 < K];
        }
    }
    exit(0);
}