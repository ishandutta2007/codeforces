#include <iostream>
#include <string>
#include <map>

constexpr int MAX = 45000;

bool judge(int n) {
    int ok = 0, ng = MAX;

    while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if (mid * mid <= n) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok * ok == n;
}

int dfs(const std::string& s) {
    static std::map<std::string, int> dp;
    if (dp.count(s)) return dp[s];

    auto& ret = dp[s];
    ret = MAX;

    if (s.empty()) {
        return ret = MAX;
    } else if (judge(std::stoi(s))) {
        return ret = 0;
    }

    int n = s.length();
    for (int i = 0; i < n; ++i) {
        auto t = s;
        t.erase(t.begin() + i);

        if (t.front() == '0') continue;
        ret = std::min(ret, dfs(t) + 1);
    }

    return ret;
}

void solve() {
    std::string n;
    std::cin >> n;

    int ans = dfs(n);
    std::cout << (ans == MAX ? -1 : ans) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}