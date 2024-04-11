#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> a(N);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
            sum ^= a[i];
        }
        std::vector<int> op;
        auto apply = [&](int i) {
            op.push_back(i);
            int x = a[i] ^ a[i + 1] ^ a[i + 2];
            a[i] = a[i + 1] = a[i + 2] = x;
        };
        auto solve_odd = [&](int l, int r) {
            assert((r - l) % 2 == 1);
            for (int i = l; i + 2 < r; i += 2) {
                apply(i);
            }
            for (int i = r - 5; i >= l; i -= 2) {
                apply(i);
            }
        };
        bool good = false;
        if (sum == 0) {
            if (N % 2) {
                good = true;
                solve_odd(0, N);
            } else {
                int pref = 0;
                for (int i = 0; i < N; i += 2) {
                    pref ^= a[i];
                    if (pref == 0) {
                        good = true;
                        solve_odd(0, i + 1);
                        solve_odd(i + 1, N);
                        break;
                    } else {
                        pref ^= a[i + 1];
                    }
                }
            }
        }
        if (!good) {
            std::cout << "NO\n";
        } else {
            assert((int)std::count(a.begin(), a.end(), 0) == N);
            std::cout << "YES\n";
            int k = (int)op.size();
            std::cout << k << '\n';
            assert(k <= N);
            for (int j = 0; j < k; ++j) {
                std::cout << op[j] + 1 << "\n "[j + 1 < k];
            }
        }
    }
    return 0;
}