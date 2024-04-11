#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<int K = 26, char offset = 'a'>
struct AhoCorasick {
    struct Node {
        int nxt[K], go[K];
        bool leaf = false;
        int p = -1, link = -1, leaflink = -1, len = 0;
        char pc;
        Node(int p = -1, char pc = offset - 1) : p(p), pc(pc) {
            fill(all(nxt), -1), fill(all(go), -1);
        }
    };
    vector<Node> trie;

    AhoCorasick() : trie(1) { }

    int add(const string& s) {
        int u = 0;
        for (auto c : s) {
            int v = trie[u].nxt[c - offset];
            if (v == -1) {
                v = (int)size(trie);
                trie.emplace_back(u, c);
                trie[v].len = trie[u].len + 1;
            }
            u = trie[u].nxt[c - offset] = v;
        }
        trie[u].leaf = true;
        trie[u].leaflink = u;
        return u;
    }
    int getlink(int v) {
        if (trie[v].link == -1) {
            if (v == 0 || trie[v].p == 0) trie[v].link = 0;
            else trie[v].link = go(getlink(trie[v].p), trie[v].pc);
        }
        return trie[v].link;
    }
    int go(int v, char c) {
        int idx = c - offset;
        if (trie[v].go[idx] == -1) {
            if (trie[v].nxt[idx] != -1) trie[v].go[idx] = trie[v].nxt[idx];
            else trie[v].go[idx] = (v == 0 ? 0 : go(getlink(v), c));
        }
        return trie[v].go[idx];
    }
    int getleaf(int v){ // inclusive
        if (trie[v].leaflink == -1) {
            if (v == 0 || trie[v].leaf) trie[v].leaflink = v;
            else trie[v].leaflink = getleaf(getlink(v));
        }
        return trie[v].leaflink;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    AhoCorasick aho;

    vector<string> s(n);
    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        id[i] = aho.add(s[i]);
    }

    int m = (int)size(aho.trie);
    vector<vector<int>> E(m);

    for (int i = 0; i < n; ++i) {
        int p = aho.getleaf(aho.getlink(id[i]));
        E[p].push_back(id[i]);
    }

    vector<int> L(m), R(m);
    int timer = 0;
    auto tour = [&](auto&& self, int u) -> void {
        L[u] = timer;
        for (auto v : E[u]) self(self, v);
        R[u] = timer++;
    };
    tour(tour, 0);

    int ans = 0;

    for (auto& x : s) {
        int k = (int)size(x);
        vector<int> left(k), st(k);
        for (int j = 0, u = 0; j < k; ++j) {
            u = aho.go(u, x[j]);
            st[j] = aho.getleaf(j == k - 1 ? aho.getlink(u) : u);
            left[j] = j - aho.trie[st[j]].len + 1;
        }
        int suffmin = k;
        vector<int> bad = {R[0]};
        for (int j = k - 1; j >= 0; --j) {
            int u = st[j];
            if (u == 0) continue;
            if (j - aho.trie[u].len + 1 < suffmin) u = aho.getleaf(aho.getlink(u));
            bad.push_back(R[u]);
            suffmin = min(suffmin, left[j]);
        }
        sort(all(bad));
        set<int> S;
        for (int j = 0; j < k; ++j) {
            auto iterl = lower_bound(all(bad), L[st[j]]);
            auto iterr = upper_bound(all(bad), R[st[j]]);
            if (iterl == iterr) S.insert(st[j]);
        }
        ans += (int)size(S);
    }

    cout << ans << endl;

    exit(0);
}