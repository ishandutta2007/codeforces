#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;
using ull = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

template<int N, typename T>
struct Trie
{
    struct Node
    {
        int nxt[2];
        T min = std::numeric_limits<T>::max();
        Node() { fill(all(nxt), -1); }
    };
    deque<Node> trie;
    Trie() : trie(1) { }
    void insert(bitset<N> mask, T value)
    {
        chmin(trie[0].min, value);
        for (int i = N - 1, u = 0; i >= 0; --i)
        {
            int& v = trie[u].nxt[mask[i]];
            if (v == -1)
            {
                v = size(trie);
                trie.emplace_back();
            }
            u = v;
            chmin(trie[u].min, value);
        }
    }
    bool check(int u, int ch, T bound)
    {
        int v = trie[u].nxt[ch];
        return v != -1 && trie[v].min <= bound;
    }
    pair<bool, T> find_max(bitset<N> mask, T bound)
    {
        int u = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            int ch = mask[i] ^ 1;
            if (check(u, ch, bound))
            {
                u = trie[u].nxt[ch];
            }
            else if (check(u, ch ^ 1, bound))
            {
                u = trie[u].nxt[ch ^ 1];
            }
            else
            {
                return pair(false, T());
            }
        }
        return pair(true, trie[u].min);
    }
};

int main()
{ _
    constexpr int N = 18;
    vector<Trie<N, ull>> trie(1 << N);

    int q; cin >> q;

    for (int z = 0; z < q; ++z)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int x; cin >> x;
            for (int d = 1; d * d <= x; ++d) if (x % d == 0)
            {
                for (auto y : { d , x / d})
                {
                    trie[y].insert(bitset<N>(x), x);
                }
            }
        }
        else
        {
            int x, k, s; cin >> x >> k >> s;

            int ans = -1;
            if (x % k == 0 && x <= s)
            {
                auto [good, res] = trie[k].find_max(bitset<N>(x), s - x);
                if (good) ans = (int)res;
            }
            cout << ans << endl;
        }
    }

    exit(0);
}