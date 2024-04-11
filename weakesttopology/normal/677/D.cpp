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

template<typename T, int... Args>
struct SegmentTree
{
    using ST = SegmentTree<T>;
    static const T id = INF;
    static T combine(T x, T y) { return min(x, y); }
    static void update(ST& a, ST& b, ST& c, T)
    {
        a.value = combine(b.value, c.value);
    }
    T value = id;
    void modify(T value) { this->value = value; }
    T query() { return value; }
};

template<typename T, int N, int... Ns>
struct SegmentTree<T, N, Ns...>
{
    using ST = SegmentTree<T>;
    using CUR = SegmentTree<T, N, Ns...>;
    using NXT = SegmentTree<T, Ns...>;
    array<SegmentTree<T, Ns...>, 2 * N> st;
    template<typename... Args>
    static void update(CUR& a, CUR& b, CUR& c, int p, Args... args)
    {
        for (int r = p + N; r; r >>= 1)
            NXT::update(a.st[r], b.st[r], c.st[r], args...);
    }
    template<typename... Args>
    void modify(int p, Args... args)
    {
        st[p += N].modify(args...);
        while (p >>= 1) NXT::update(st[p], st[p << 1], st[p << 1 | 1], args...);
    }
    template<typename... Args>
    T query(int l, int r, Args... args)
    {
        T resl = ST::id, resr = ST::id;
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) resl = ST::combine(resl, st[l++].query(args...));
            if (r & 1) resr = ST::combine(st[--r].query(args...), resr);
        }
        return ST::combine(resl, resr);
    }
};

int main()
{ _
    int n, m, p; cin >> n >> m >> p;

    using ii = pair<int, int>;
    map<int, vector<ii>> H;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            int x; cin >> x;
            H[x].push_back(pair(i, j));
        }

    constexpr int N = 300;
    SegmentTree<int, N, N> st[4];

    vector dp(n, vector(m, INF));

    auto rotate = [&](int i, int j) { return pair{N - 1 - j, i}; };
    auto chmin = [](int& x, int y) { x = min(x, y); };

    for (auto [x, v] : H)
    {
        for (auto [i, j] : v)
        {
            if (x == 1) dp[i][j] = i + j;
            else
            {
                int k = i, l = j;
                for (int t = 0; t < 4; ++t)
                {
                    tie(k, l) = rotate(k, l);
                    chmin(dp[i][j], st[t].query(0, k, 0, l) + k + l);
                }
            }
        }

        if (x != 1)
        {
            for (auto [i, j] : H[x - 1])
                for (int t = 0; t < 4; ++t)
                {
                    tie(i, j) = rotate(i, j);
                    st[t].modify(i, j, INF);
                }
        }

        for (auto [i, j] : v)
        {
            int z = dp[i][j];
            for (int t = 0; t < 4; ++t)
            {
                tie(i, j) = rotate(i, j);
                st[t].modify(i, j, z - i - j);
            }
        }
    }

    auto [i, j] = H[p].back();

    int ans = dp[i][j];

    cout << ans << endl;

    exit(0);
}