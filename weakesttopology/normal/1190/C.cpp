#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    std::cin >> N >> K;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        char c;
        std::cin >> c;
        a[i] = c - '0';
    }
    std::set<int> on[2];
    for (int i = 0; i < N; ++i) {
        on[a[i]].insert(i);
    }
    bool win = false, stall = false;
    for (int t : {0, 1}) {
        if (on[t].empty() || *on[t].rbegin() - *on[t].begin() < K) {
            win = true;
        }
    }
    for (int i = 0; i < K; ++i) {
        on[a[i]].erase(i);
    }
    for (int i = 0; i + K <= N; ++i) {
        for (auto t : {0, 1}) {
            if (!(on[t].empty() || *on[t].rbegin() - *on[t].begin() < K)) {
                stall = true;
            }
        }
        on[a[i]].insert(i);
        if (i + K < N) {
            on[a[i + K]].erase(i + K);
        }
    }
    std::cout << (win ? "tokitsukaze" : stall ? "once again" : "quailty") << '\n';
    exit(0);
}