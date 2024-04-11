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
        std::stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
            while (stk.top() != -1 && a[stk.top()] <= a[i]) {
                stk.pop();
            }
            stk.push(i);
        }
        std::cout << stk.size() - 2 << '\n';
    }
    exit(0);
}