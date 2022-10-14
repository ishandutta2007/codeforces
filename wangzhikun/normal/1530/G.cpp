// orz jiangly
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string a, b;
    std::cin >> a >> b;
    
    if (a == b) {
        std::cout << "0\n";
        return;
    }
    
    int cnt = std::count(a.begin(), a.end(), '1');
    if (std::count(b.begin(), b.end(), '1') != cnt) {
        std::cout << "-1\n";
        return;
    }
    
    if (k == 0 || k > cnt) {
        std::cout << "-1\n";
        return;
    }
    
    auto solve = [&](std::string &s) {
        std::vector<std::pair<int, int>> ans;
        
        auto reverse = [&](int l, int r) {
            ans.emplace_back(l, r);
            std::reverse(s.begin() + l, s.begin() + r);
        };
        
        std::vector<int> a, pos;
        auto get = [&]() {
            a.clear();
            pos = {-1};
            int lst = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    pos.push_back(i);
                    a.push_back(i - lst - 1);
                    lst = i;
                }
            }
            a.push_back(n - lst - 1);
            pos.push_back(n);
        };
        get();
        
        for (int i = cnt; i >= k; i--) {
            if (a[i] > 0) {
                reverse(pos[i - k + 1], pos[i + 1]);
                get();
                assert(a[i] == 0);
            }
        }
        
        if (k == cnt) {
            auto b = a;
            std::reverse(b.begin() + 1, b.end() - 1);
            if (b < a) {
                reverse(pos[1], pos[k] + 1);
            }
            return ans;
        }
        
        if (k % 2 == 1) {
            for (int i = 0; i < k - 1; i++) {
                reverse(pos[2], pos[k + 1] + 1);
                get();
                reverse(pos[1], pos[k + 1]);
                get();
            }
        } else {
            for (int i = 0; i < k - 1; i++) {
                reverse(pos[1] + 1, pos[k + 1] + 1);
                get();
                reverse(pos[1], pos[k + 1]);
                get();
            }
        }
        
        return ans;
    };
    
    auto ans1 = solve(a);
    auto ans2 = solve(b);
    
    if (a != b) {
        std::cout << "-1\n";
        return;
    }
    
    std::reverse(ans2.begin(), ans2.end());
    ans1.insert(ans1.end(), ans2.begin(), ans2.end());
    
    std::cout << ans1.size() << "\n";
    for (auto [x, y] : ans1) {
        std::cout << x + 1 << " " << y << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}