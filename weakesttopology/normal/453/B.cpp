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

auto sieve(int N)
{
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr)
        {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

bool chmin(auto& x, const auto& y) { return y < x ? (x = y, true) : false; }
bool chmax(auto& x, const auto& y) { return x < y ? (x = y, true) : false; }
 
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
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    constexpr int N = 59;
    auto [lp, pr] = sieve(N);
    const int M = size(pr), fullmask = (1 << M) - 1;

    vector<int> f(N + 1, 0);
    for (int x = 2; x <= N; ++x)
    {
        for (int j = 0; j < M; ++j)
        {
            if (x % pr[j] == 0) f[x] |= 1 << j;
        }
    }

    Recovery<int> rec;
    vector<Recovery<int>::Node*> last(1 << M, nullptr), lastnxt(1 << M, nullptr);

    vector<int> dp(1 << M, 0), dpnxt(1 << M, INF);

    for (auto x : a)
    {
        for (int y = 1; y <= N; ++y)
        {
            for (int mask = fullmask ^ f[y]; ; (--mask) &= ~f[y])
            {
                int newmask = mask ^ f[y];
                if (chmin(dpnxt[newmask], dp[mask] + abs(x - y)))
                {
                    lastnxt[newmask] = rec.create(y, last[mask]);
                }
                if (mask == 0) break;
            }
        }
        fill(all(dp), INF), swap(dp, dpnxt);
        fill(all(last), nullptr), swap(last, lastnxt);
    }

    auto iter = min_element(all(dp));
    int opt = (int)distance(begin(dp), iter);

    auto b = rec.recover(last[opt]);

    for (int i = 0; i < n; ++i) cout << b[i] << "\n "[i + 1 < n];

    exit(0);
}