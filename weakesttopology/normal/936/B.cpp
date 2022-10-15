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

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

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
    int n, m; cin >> n >> m;

    vector<vector<int>> E(n);

    for (int u = 0; u < n; ++u)
    {
        int deg; cin >> deg;
        for (int j = 0; j < deg; ++j)
        {
            int v; cin >> v; --v;
            E[u].push_back(v);
        }
    }

    constexpr int max_turns = 1e6;

    vector<vector<int>> dp(2, vector<int>(n, -1));

    Recovery<int> rec;
    vector last(2, vector<Recovery<int>::Node*>(n, nullptr));

    function<int(int, int)> solve = [&](int b, int u)
    {
        int& memo = dp[b][u];
        if (memo != -1) return memo;

        if (empty(E[u]))
        {
            last[b][u] = rec.create(u, nullptr);
            return memo = (b ? 0 : INF); 
        }

        memo = max_turns;

        int nxt = INF;
        for (auto v : E[u])
        {
            if (chmin(nxt, 1 + solve(b ^ 1, v)))
            {
                last[b][u] = rec.create(u, last[b ^ 1][v]);
            }
        }

        return memo = nxt;
    };

    int s; cin >> s; --s;

    int res = solve(0, s);

    debug(res);

    if (res < max_turns)
    {
        auto ans = rec.recover(last[0][s]);
        int r = size(ans);

        reverse(all(ans));

        cout << "Win" << endl;
        //cout << r << endl;

        for (int j = 0; j < r; ++j)
        {
            cout << ans[j] + 1 << "\n "[j + 1 < r];
        }
    }
    else if (res >= INF)
    {
        cout << "Lose" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }

    exit(0);
}