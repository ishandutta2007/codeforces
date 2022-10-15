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

template<typename T> struct Recovery
{
    struct Node
    {
        T value;
        Node* prev;
        Node(T value = T(), Node* prev = nullptr) : value(value), prev(prev) { }
    };
    deque<Node> states;
    Node* create(T value, Node* prev)
    {
        return &states.emplace_back(value, prev);
    }
    vector<T> recover(Node* last) const
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
    string s; cin >> s;
    int n = size(s);

    constexpr int K = 3;

    vector<int> dp(K, INF), dpnxt(K, INF);

    Recovery<int> rec;
    vector<Recovery<int>::Node*> last(K, nullptr), lastnxt(K, nullptr);

    bool zero = false;

    for (int i = 0; i < n; ++i)
    {
        int d = (s[i] - '0') % K;

        for (int x = 0; x < K; ++x)
        {
            dpnxt[x] = dp[x] + 1;
            lastnxt[x] = last[x];
        }

        if (s[i] != '0')
        {
            if (chmin(dpnxt[d], i))
            {
                lastnxt[d] = rec.create(i, nullptr);
            }
        }
        else zero = true;

        for (int x = 0; x < K; ++x)
        {
            int y = (10 * x + d) % K;
            if (chmin(dpnxt[y], dp[x]))
            {
                lastnxt[y] = rec.create(i, last[x]);
            }
        }

        swap(dp, dpnxt), swap(lastnxt, last);
    }

    if (dp[0] >= INF && zero)
    {
        cout << 0 << endl;
    }
    else if (dp[0] < INF)
    {
        auto keep = rec.recover(last[0]);
        for (auto i : keep) cout << s[i];
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    exit(0);
}