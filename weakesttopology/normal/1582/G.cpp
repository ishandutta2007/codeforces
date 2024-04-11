#include <bits/stdc++.h>
std::pair<std::vector<int>, std::vector<int>> sieve(int N) {
    std::vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            pr.push_back(lp[i] = i);
        }
        for (auto p : pr) {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return {lp, pr};
}
constexpr int amax = 1e6;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    auto [lp, pr] = sieve(amax + 1);
    std::vector<int> pos(amax + 1);
    for (int i = 0; i < pr.size(); ++i) {
        pos[pr[i]] = i;
    }
    std::string b;
    std::cin >> b;
    std::vector<int> L(N);
    std::vector<std::stack<int>> occ(pr.size());
    for (int i = 0; i < N; ++i) {
        L[i] = i;
        if (b[i] == '*') {
            for (int x = a[i]; x != 1; x /= lp[x]) {
                int j = pos[lp[x]];
                occ[j].push(i);
            }
        } else {
            for (int x = a[i]; x != 1; x /= lp[x]) {
                int j = pos[lp[x]];
                if (occ[j].empty()) {
                    L[i] = -1;
                } else {
                    L[i] = std::min(L[i], occ[j].top());
                    occ[j].pop();
                }
            }
        }
    }
    int64_t ans = 0;
    std::stack<int> stk;
    for (int l = N - 1; l >= 0; --l) {
        while (!stk.empty() && L[l] <= L[stk.top()]) {
            stk.pop();
        }
        if (L[l] >= l) {
            ans += (stk.empty() ? N : stk.top()) - l;
        }
        stk.push(l);
    }
    std::cout << ans << '\n';
    exit(0);
}