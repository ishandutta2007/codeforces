#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int K = 30;
struct Trie {
    struct Node {
        int go[2];
        Node() : go{-1, -1} {}
    };
    vector<Node> tr;
    Trie() : tr(1) {}
    void insert(bitset<K> s) {
        for (int k = K - 1, u = 0; k >= 0; --k) {
            int b = s[k];
            if (tr[u].go[b] == -1) {
                tr[u].go[b] = (int)size(tr);
                tr.emplace_back();
            }
            u = tr[u].go[b];
        }
    }
    int minmatch(bitset<K> s) {
        for (int k = K - 1, u = 0; k >= 0; --k) {
            int b = s[k];
            if (tr[u].go[b] == -1) b ^= 1;
            s[k] = s[k] ^ b;
            u = tr[u].go[b];
        }
        return (int)s.to_ullong();
    }
};
ll solve(const vector<int>& a, int k = K - 1) {
    if (empty(a) || k < 0) return 0LL;
    vector<int> b[2];
    for (auto x : a) {
        b[x >> k & 1].push_back(x);
    }
    ll res = 0;
    if (not empty(b[0]) && not empty(b[1])) {
        Trie tr;
        for (auto x : b[0]) tr.insert(x);
        int cost = b[0][0] ^ b[1][0];
        for (auto x : b[1]) {
            cost = min(cost, tr.minmatch(x));
        }
        res += cost;
    }
    if (not empty(b[1])) {
        for (auto& x : b[1]) {
            x ^= 1 << k;
        }
    }
    res += solve(b[0], k - 1) + solve(b[1], k - 1);
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int u = 0; u < n; ++u) {
        cin >> a[u];
    }
    cout << solve(a) << endl;
    exit(0);
}