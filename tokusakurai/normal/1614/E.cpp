#include <bits/stdc++.h>
using namespace std;

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template <int char_size, char base>
struct Trie {
    struct Node {
        vector<int> next, accept;
        int count; // 

        Node() : next(char_size, -1), count(0) {}
    };

    vector<Node> nodes;

    Trie() { nodes.emplace_back(); }

    int count() const { return nodes.front().count; }

    int size() const { return nodes.size(); }

    void insert(const string &s, int id) {
        int now = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int &next = nodes[now].next[s[i] - base];
            if (next == -1) {
                next = size();
                nodes.emplace_back();
            }
            nodes[now].count++;
            now = next;
        }
        nodes[now].count++;
        nodes[now].accept.push_back(id);
    }

    void insert(const string &s) { insert(s, count()); }

    bool search(const string &s, bool prefix = false) const {
        int now = 0;
        for (int i = 0; i < s.size(); i++) {
            now = nodes[now].next[s[i] - base];
            if (now == -1) return false;
        }
        return (prefix) ? true : !nodes[now].accept.empty();
    }
};

template <typename T, int MAX_LOG>
struct Binary_Trie {
    struct Node {
        array<int, 2> next;
        int count;

        Node() : next{-1, -1}, count(0) {}
    };

    vector<Node> nodes;

    Binary_Trie() { nodes.emplace_back(); }

    void insert(const T &x, int id) {
        int now = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int t = (x >> i) & 1;
            int next = nodes[now].next[t];
            if (next == -1) {
                next = nodes.size();
                nodes[now].next[t] = next;
                nodes.emplace_back();
            }
            nodes[now].count++;
            now = next;
        }
        nodes[now].count++;
    }

    void insert(const T &x) { insert(x, nodes[0].count); }

    void erase(const T &x) {
        if (!count(x)) return;
        int now = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int t = (x >> i) & 1;
            nodes[now].count--;
            now = nodes[now].next[t];
        }
        nodes[now].count--;
    }

    int find(const T &x) const {
        int now = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int t = (x >> i) & 1;
            int next = nodes[now].next[t];
            if (next == -1) return -1;
            now = next;
        }
        return now;
    }

    int count(const T &x) {
        int p = find(x);
        return p == -1 ? 0 : nodes[p].count;
    }

    T max_element(const T &xor_val = 0) const {
        int now = 0;
        T ret = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int t = (xor_val >> i) & 1;
            int l = nodes[now].next[t], r = nodes[now].next[t ^ 1];
            if (r == -1 || nodes[r].count == 0) {
                now = l;
                ret |= T(t) << i;
            } else {
                now = r;
                ret |= T(t ^ 1) << i;
            }
        }
        return ret;
    }

    T min_element(const T &xor_val = 0) const {
        int now = 0;
        T ret = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int t = (xor_val >> i) & 1;
            int l = nodes[now].next[t], r = nodes[now].next[t ^ 1];
            if (l == -1 || nodes[l].count == 0) {
                now = r;
                ret |= T(t ^ 1) << i;
            } else {
                now = l;
                ret |= T(t) << i;
            }
        }
        return ret;
    }

    T kth_element(int k, const T &xor_val = 0) const { // k  (0-indexed)
        int now = 0;
        T ret = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int t = (xor_val >> i) & 1;
            int l = nodes[now].next[t], r = nodes[now].next[t ^ 1];
            if (l == -1 || nodes[l].count <= k) {
                now = r;
                k -= (l == -1 ? 0 : nodes[l].count);
                ret |= T(t ^ 1) << i;
            } else {
                now = l;
                ret |= T(t) << i;
            }
        }
        return ret;
    }

    int count_less(const T &x, const T &xor_val = 0) const { // x 
        int now = 0;
        int ret = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int t = (xor_val >> i) & 1, s = (x >> i) & 1;
            int l = nodes[now].next[t], r = nodes[now].next[t ^ 1];
            if (s != t && l != -1) ret += nodes[l].count;
            now = nodes[now].next[s];
            if (now == -1) break;
        }
        return ret;
    }
};

int main() {
    int N;
    cin >> N;

    int MAX = 1000000;
    int MOD = 1000000001;
    int last_ans = 0;

    Binary_Trie<int, 31> trie;

    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
        T += MAX;

        int l1 = T - MAX, r1 = T + MAX; // (l1,r1]

        while (r1 - l1 > 1) {
            int m1 = (l1 + r1) / 2;
            int x = trie.count_less(m1);
            (m1 + i - x < T ? l1 : r1) = m1;
        }

        int l2 = T - MAX, r2 = T + MAX; // [l2,r2)

        while (r2 - l2 > 1) {
            int m2 = (l2 + r2) / 2;
            int x = trie.count_less(m2);
            (m2 + i - x <= T ? l2 : r2) = m2;
        }

        trie.insert(l1), trie.insert(l2);
        // cout << l1 - MAX << ' ' << l2 - MAX << '\n';

        int K;
        cin >> K;

        while (K--) {
            int X;
            cin >> X;
            X = (last_ans + X) % MOD;
            X += MAX;

            last_ans = X + i + 1 - trie.count_less(X) - MAX;

            cout << last_ans << '\n';
        }
    }
}