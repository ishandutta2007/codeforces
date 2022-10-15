#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int query(const vector<int>& I) {
    cout << "?";
    for (auto i : I) cout << " " << i + 1;
    cout << endl;
    int res;
    cin >> res;
    return res;
}
template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
template<typename T>
struct Recovery {
    struct Node {
        T value;
        Node* prev;
        Node(T value, Node* prev) : value(value), prev(prev) { }
    };
    deque<Node> states;
    Node* create(T value, Node* prev) {
        return &states.emplace_back(value, prev);
    } 
    vector<T> recover(Node* last) {
        vector<T> res;
        while (last != nullptr) {
            res.push_back(last->value);
            last = last->prev;
        }
        reverse(begin(res), end(res));
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    const int inf = 1e6;
    vector<int> dp(n + 1, inf);
    vector<Recovery<int>::Node*> last(n + 1, nullptr);
    Recovery<int> rec;
    dp[0] = 0;
    while (true) {
        bool converged = true;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y <= min(x, k); ++y) {
                if (n < x + k - y) continue;
                int z = x - y + (k - y);
                if (chmin(dp[z], dp[x] + 1)) {
                    last[z] = rec.create(y, last[x]);
                    converged = false;
                }
            }
        }
        if (converged) break;
    }
    if (dp[n] == inf) {
        cout << -1 << endl;
        exit(0);
    }
    vector<int> I[2];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) I[0].push_back(i);
    auto ops = rec.recover(last[n]);
    int ans = 0;
    for (auto x : ops) {
        vector<int> J;
        int cnt[2] = {k - x, x};
        for (auto t : {0, 1}) {
            for (int i = 0; i < cnt[t]; ++i) {
                int j = I[t].back();
                J.push_back(j);
                I[t].pop_back();
                b[j] ^= 1;
            }
        }
        for (auto j : J) {
            I[b[j]].push_back(j);
        }
        ans ^= query(J);
    }
    cout << "! " << ans << endl;
    exit(0);
}