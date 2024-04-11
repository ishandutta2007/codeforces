#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<int N>
struct Trie {
    struct Node {
        int nxt[2];
        int w = 0;
        Node() { fill(all(nxt), -1); }
    };
    deque<Node> trie;
    Trie() : trie(1) {}

    void add(bitset<N> s) {
        for (int i = N - 1, u = 0; i >= 0; --i) {
            int& v = trie[u].nxt[s[i]];
            if (v == -1) {
                v = (int)size(trie);
                trie.emplace_back();
            }
            u = v;
            trie[u].w += 1;
        }
    }
    bitset<N> take(bitset<N> s) {
        bitset<N> res;
        for (int i = N - 1, u = 0; i >= 0; --i) {
            int b = s[i], v = trie[u].nxt[b];
            if (v == -1 || trie[v].w == 0) b ^= 1;
            res[i] = b;
            u = trie[u].nxt[b];
            trie[u].w -= 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    constexpr int N = 30;
    Trie<N> trie;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        trie.add(x);
    }

    for (int i = 0; i < n; ++i) {
        bitset<N> x(a[i]);
        x ^= trie.take(x);
        cout << x.to_ullong() << "\n "[i + 1 < n];
    }

    exit(0);
}