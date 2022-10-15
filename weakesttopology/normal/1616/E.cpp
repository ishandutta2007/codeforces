#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int Q;
    std::cin >> Q;
    for (int qq = 0; qq < Q; ++qq) {
        int N;
        std::cin >> N;
        std::string s, t;
        std::cin >> s >> t;
        std::map<char, std::queue<int>> q;
        ordered_set<int> S;
        for (int i = 0; i < N; ++i) {
            q[s[i]].push(i);
            S.insert(i);
        }
        int64_t ans = -1, last = -1;
        int64_t cost = 0;
        for (int i = 0; i < N; ++i) {
            char c = t[i];
            for (char d = 'a'; d < c; ++d) {
                if (q[d].empty()) continue;
                int64_t ncost = cost + S.order_of_key(q[d].front());
                ans = (ans == -1 ? ncost : std::min(ans, ncost));
            }
            if (q[c].empty()) break;
            cost += S.order_of_key(q[c].front());
            S.erase(q[c].front());
            q[c].pop();
        }
        std::cout << ans << '\n';
    }
    exit(0);
}