#include "bits/stdc++.h"

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> p(N, -1), a(N);
    //std::vector<int> real(N);
    //for (int i = 0; i < N; ++i) {
    //    std::cin >> real[i];
    //    --real[i];
    //}
    auto query = [&]() {
        std::cout << '?';
        for (int i = 0; i < N; ++i) {
            std::cout << ' ' << a[i];
        }
        std::cout << std::endl;
        int k;
        std::cin >> k;
        return --k;
        //for (int k = 0; k < N; ++k) {
        //    for (int j = k + 1; j < N; ++j) {
        //        if (real[k] + a[k] == real[j] + a[j]) {
        //            return k;
        //        }
        //    }
        //}
        //return -1;
    };
    std::fill(a.begin(), a.end(), 1);
    p[N - 1] = 0;
    for (int x = 2; x <= N; ++x) {
        a[N - 1] = x;
        int k = query();
        if (k == -1) {
            p[N - 1] = N + 1 - x;
            break;
        }
    }
    for (int x = 0; x < p[N - 1]; ++x) {
        std::fill(a.begin(), a.end(), p[N - 1] + 1 - x);
        a[N - 1] = 1;
        int k = query();
        assert(k != -1);
        p[k] = x;
    }
    for (int x = p[N - 1] + 1; x < N; ++x) {
        std::fill(a.begin(), a.end(), 1);
        a[N - 1] = x + 1 - p[N - 1];
        int k = query();
        assert(k != -1);
        p[k] = x;
    }
    std::cout << '!';
    for (int i = 0; i < N; ++i) {
        std::cout << ' ' << p[i] + 1;
    }
    std::cout << std::endl;
    exit(0);
}