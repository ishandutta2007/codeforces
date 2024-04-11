#include <bits/stdc++.h>
template<typename T>
struct Recovery {
    struct Node {
        T value;
        Node* prev;
        Node(T value, Node* prev) : value(value), prev(prev) { }
    };
    std::deque<Node> states;
    Node* create(T value, Node* prev) {
        return &states.emplace_back(value, prev);
    } 
    std::vector<T> recover(Node* last) {
        std::vector<T> res;
        while (last != nullptr) {
            res.push_back(last->value);
            last = last->prev;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<std::string> S(N);
        std::vector<std::map<char, std::vector<int>>> pos(N);
        std::vector<char> chs;
        for (int i = 0; i < N; ++i) {
            std::cin >> S[i];
            for (int j = 0; j < S[i].size(); ++j) {
                pos[i][S[i][j]].push_back(j);
            }
            chs.insert(chs.end(), S[i].begin(), S[i].end());
        }
        std::sort(chs.begin(), chs.end());
        chs.erase(std::unique(chs.begin(), chs.end()), chs.end());
        std::vector<std::map<char, int>> dp(1 << N);
        std::priority_queue<std::tuple<int, int, char>> pq;
        Recovery<char> rec;
        std::vector<std::map<char, Recovery<char>::Node*>> last(1 << N);
        for (auto ch : chs) {
            bool good = true;
            for (int i = 0; i < N; ++i) {
                if (!pos[i].count(ch)) {
                    good = false;
                    break;
                }
            }
            if (good) {
                dp[0][ch] = 1;
                last[0][ch] = rec.create(ch, nullptr);
                pq.emplace(1, 0, ch);
            }
        }
        int ans = 0, best_mask = 0;
        char best_ch = chs[0];
        while (!pq.empty()) {
            auto [len, mask, ch] = pq.top();
            pq.pop();
            if (dp[mask][ch] != len) continue;
            if (ans < len) {
                ans = len;
                best_mask = mask;
                best_ch = ch;
            }
            for (auto nch : chs) {
                int nmask = 0;
                bool good = true;
                for (int i = 0; i < N; ++i) {
                    const auto& I = pos[i][nch];
                    auto iter = I.begin();
                    int j = pos[i][ch][mask >> i & 1];
                    while (iter != I.end() && *iter <= j) ++iter;
                    if (iter == I.end()) {
                        good = false;
                        break;
                    } else {
                        nmask |= (iter - I.begin()) << i;
                    }
                }
                if (good && len + 1 > dp[nmask][nch]) {
                    dp[nmask][nch] = len + 1;
                    last[nmask][nch] = rec.create(nch, last[mask][ch]);
                    pq.emplace(len + 1, nmask, nch);
                }
            }
        }
        std::cout << ans << '\n';
        auto path = rec.recover(last[best_mask][best_ch]);
        for (auto c : path) {
            std::cout << c;
        }
        std::cout << '\n';
    }
    exit(0);
}