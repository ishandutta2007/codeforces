#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <queue>
#include <functional>

template <int K, class T>
struct PatternsMatching {
    struct Node {
        std::array<int, K> nxt;
        int fail;
        bool matched;

        explicit Node() : fail(0), matched(false) { nxt.fill(-1); }
    };

    std::vector<Node> nodes;
    std::function<int(T)> enc;

    explicit PatternsMatching(T base) {
        nodes.emplace_back();
        enc = [=](T c) { return c - base; };
    }

    explicit PatternsMatching(const std::function<int(T)>& enc)
        : enc(enc) { nodes.emplace_back(-1); }

    template <class Container>
    void add(const Container& s) {
        int pos = 0;
        for (T ci : s) {
            int c = enc(ci);

            int npos = nodes[pos].nxt[c];
            if (npos == -1) {
                npos = nodes.size();
                nodes[pos].nxt[c] = npos;
                nodes.emplace_back();
            }
            pos = npos;
        }
        nodes[pos].matched = true;
    }

    // bfsfail
    void build() {
        std::queue<int> que;
        for (int& pos : nodes[0].nxt) {
            if (pos == -1) {
                pos = 0;
            } else {
                que.push(pos);
            }
        }

        while (!que.empty()) {
            int pos = que.front();
            que.pop();

            for (int c = 0; c < K; ++c) {
                int npos = nodes[pos].nxt[c];
                if (npos == -1) continue;

                int p = nodes[pos].fail;
                while (nodes[p].nxt[c] == -1) p = nodes[p].fail;
                int fpos = next(nodes[pos].fail, c);

                nodes[npos].fail = fpos;
                if (nodes[fpos].matched) nodes[npos].matched = true;

                que.push(npos);
            }
        }
    }

    int next(int pos, int c) const {
        while (nodes[pos].nxt[c] == -1) pos = nodes[pos].fail;
        return nodes[pos].nxt[c];
    }

    Node& operator[](int pos) { return nodes[pos]; }
    Node operator[](int pos) const { return nodes[pos]; }
};

int x;
std::vector<std::string> ps;

// 
bool judge(const std::string& t) {
    int n = t.length();
    for (int l = 0; l < n; ++l) {
        int sum = 0;
        for (int r = l; r < n; ++r) {
            sum += t[r] - '0';
            if (sum != x && x % sum == 0) return true;
        }
    }
    return false;
}

// x
void dfs(std::string& t, int dsum) {
    if (dsum == x && !judge(t)) ps.push_back(t);

    for (int d = 1; d <= 9 && dsum + d <= x; ++d) {
        t.push_back(d + '0');
        dfs(t, dsum + d);
        t.pop_back();
    }
}

constexpr int INF = 1 << 30;

void solve() {
    std::string s;
    std::cin >> s >> x;

    // 
    {
        std::string tmp;
        dfs(tmp, 0);
    }

    PatternsMatching<9, char> pm('1');
    for (const auto& p : ps) pm.add(p);
    pm.build();

    int n = pm.nodes.size();

    // Trieindex
    std::vector<int> dp(n, INF);
    dp[0] = 0;

    for (char c : s) {
        std::vector<int> ndp(n, INF);

        for (int pos = 0; pos < n; ++pos) {
            ndp[pos] = std::min(ndp[pos], dp[pos] + 1);

            int npos = pm.next(pos, pm.enc(c));
            if (!pm[npos].matched) {
                ndp[npos] = std::min(ndp[npos], dp[pos]);
            }
        }

        std::swap(dp, ndp);
    }

    std::cout << *std::min_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}