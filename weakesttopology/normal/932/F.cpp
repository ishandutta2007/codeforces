#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// May define any kind of function,
// as long as intersections are unique.

// Linear function:

template<typename T>
struct Function
{
    T a = 0, b = numeric_limits<T>::max();
    T get(T x) { return a * x + b; }
};

template<typename Func, typename Codomain, typename Domain=Codomain>
struct LiChaoTree
{
    Domain L, R;
    Func id;
    vector<Func> st;
    vector<int> LEFT, RIGHT;

    LiChaoTree(Domain L, Domain R, Func id) : L(L), R(R), id(id) { create(); }

    int size() { return sz(st); }
    int create()
    {
        LEFT.push_back(-1), RIGHT.push_back(-1);
        st.push_back(id);
        return size() - 1;
    }
    int getleft(int p) { return LEFT[p] == -1 ? LEFT[p] = create() : LEFT[p]; }
    int getright(int p) { return RIGHT[p] == -1 ? RIGHT[p] = create() : RIGHT[p]; }

    void update(Func nw)
    {
        Domain l = L, r = R;
        int p = 0;
        while (l <= r)
        {
            Domain m = l + (r - l) / 2;

            bool left = nw.get(l) < st[p].get(l);
            bool mid = nw.get(m) < st[p].get(m);

            if (mid) swap(nw, st[p]);

            if (left != mid)
            {
                p = getleft(p);
                r = m;
            }
            else
            {
                p = getright(p);
                l = m + 1;
            }
        }
    }
    Codomain compute(Domain x) // returns minimum
    {
        Codomain res = numeric_limits<Codomain>::max();
        Domain l = L, r = R;
        int p = 0;
        while (l <= r)
        {
            res = min(res, st[p].get(x));
            Domain m = l + (r - l) / 2;
            if (x == m) break;
            else if (x < m)
            {
                p = getleft(p);
                r = m;
            }
            else
            {
                l = m + 1;
                p = getright(p);
            }
        }
        return res;
    }
    friend void swap(LiChaoTree& lhs, LiChaoTree& rhs)
    {
        std::swap(lhs.L, rhs.L);
        std::swap(lhs.R, rhs.R);
        std::swap(lhs.id, rhs.id);
        std::swap(lhs.st, rhs.st);
        std::swap(lhs.LEFT, rhs.LEFT);
        std::swap(lhs.RIGHT, rhs.RIGHT);
    }
};

int main()
{ _
    int n; cin >> n;
    vector a(n, 0), b(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector E(n, vector(0, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    const int N = 1e5 + 1;
    using F = Function<ll>;
    using LCT = LiChaoTree<F, ll, int>;

    vector dp(n, LINF);
    function<LCT(int, int)> compute = [&](int u, int p)
    {
        LCT h(-N, N, F());
        for (auto v : E[u])
            if (v != p)
            {
                auto g = compute(v, u);
                if (sz(g) > sz(h)) swap(g, h);
                for (auto nw : g.st) h.update(nw);
            }

        if (sz(h.st) == 1) dp[u] = 0LL;
        else dp[u] = h.compute(a[u]);

        h.update(F{b[u], dp[u]});

        return h;
    };

    compute(0, 0);

    for (int u = 0; u < n; ++u)
        cout << dp[u] << " ";
    cout << endl;

    exit(0);
}