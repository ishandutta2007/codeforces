#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
struct Recovery
{
    struct Node
    {
        T value;
        Node* prev;
        Node(T value, Node* prev) : value(value), prev(prev) { }
    };
    deque<Node> states;
    Node* create(T value, Node* prev)
    {
        return &states.emplace_back(value, prev);
    } 
    vector<T> recover(Node* last)
    {
        vector<T> res;
        while (last != nullptr)
        {
            res.push_back(last->value);
            last = last->prev;
        }
        reverse(all(res));
        return res;
    }
};

int main()
{ _
    int n, x;
    cin >> n >> x;

    vector<vector<int>> E(n);
    for (int u = 1; u < n; ++u)
    {
        int p;
        cin >> p;
        --p;
        E[p].push_back(u);
    }

    vector<int> h(n, -1), freq(n, 0);
    h[0] = 0;
    auto dfs = [&](auto& self, int u) -> void
    {
        freq[h[u]] += 1;
        for (auto v : E[u])
        {
            h[v] = h[u] + 1;
            self(self, v);
        }
    };
    dfs(dfs, 0);

    vector<int> cnt(n + 1, 0);
    vector<vector<int>> S(n + 1);
    for (int x = 0; x < n; ++x)
    {
        cnt[freq[x]] += 1;
        S[freq[x]].push_back(x);
    }

    Recovery<int> rec;
    vector<Recovery<int>::Node*> last(n + 1, nullptr);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int x = 1; x <= n; ++x) if (cnt[x])
    {
        for (int y = n - x; y >= 0; --y) if (dp[y])
        {
            for (int k = 1; k <= cnt[x] && y + k * x <= n; ++k)
            {
                int z = y + k * x;
                if (dp[z]) break;
                dp[z] = 1, last[z] = rec.create(x, last[z - x]);
            }
        }
    }

    char ch[2] = { 'a', 'b' };

    int opt = *max_element(all(h)) + 1;
    string res(n, ch[1]);

    if (dp[x])
    {
        auto path = rec.recover(last[x]);
        vector<int> take(n, 0);

        for (auto x : path)
        {
            take[S[x].back()] = 1;
            S[x].pop_back();
        }

        for (int u = 0; u < n; ++u)
        {
            if (take[h[u]]) res[u] = ch[0];
        }
    }
    else
    {
        opt += 1;

        vector<vector<int>> H(n);
        for (int u = 0; u < n; ++u) H[h[u]].push_back(u);
        for (int z = 0; z < n; ++z)
        {
            sort(all(H[z]), [&](int u, int v){ return size(E[u]) > size(E[v]); });
        }

        int ct[2] = { x, n - x };
        for (int z = 0; z < n; ++z)
        {
            int idx = ct[0] > ct[1] ? 0 : 1;

            int k = size(H[z]);
            for (int j = 0; j < k; ++j)
            {
                for (int t = 0; t < 2; ++t) if (ct[idx ^ t])
                {
                    ct[idx ^ t] -= 1;
                    res[H[z][j]] = ch[idx ^ t];
                    break;
                }
            }
        }
    }

    cout << opt << endl;
    cout << res << endl;

    exit(0);
}