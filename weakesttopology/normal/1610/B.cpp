#include <bits/stdc++.h>
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
        bool good = true;
        for (int i = 0; i < N / 2; ++i) {
            if (a[i] != a[N - 1 - i]) {
                good = false;
                break;
            }
        }
        if (!good) {
            int s = 0, t = N - 1;
            while (a[s] == a[t]) {
                ++s;
                --t;
            }
            for (auto x : {a[s], a[t]}) {
                int l = s, r = t;
                bool failed = false;
                while (l < r) {
                    if (a[l] == a[r]) {
                        ++l;
                        --r;
                    } else if (a[l] == x) {
                        ++l;
                    } else if (a[r] == x) {
                        --r;
                    } else {
                        failed = true;
                        break;
                    }
                }
                if (!failed) {
                    good = true;
                    break;
                }
            }
        }
        std::cout << (good ? "YES" : "NO") << '\n';
    }
    exit(0);
}