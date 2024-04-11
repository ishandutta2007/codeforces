#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
class PersistentST
{
private:
    const int n;
    const T Tid;
    const function<T(T, T)> op;
    vector<T> st;
    vector<int> left, right, root, last;
    int create(int version)
    {
        left.push_back(-1);
        right.push_back(-1);
        last.push_back(version);
        st.push_back(Tid);
        return sz(st) - 1;
    }
    int copy(int p, int version)
    {
        if (p != -1 && version == last[p]) return p;
        int q = create(version);
        if (p == -1) return q;
        st[q] = st[p], left[q] = left[p], right[q] = right[p];
        return q;
    }
    void modify(int p, int l, int r, int pos, T value)
    {
        if (l == r) st[p] = value;
        else
        {
            int m = l + (r - l) / 2;
            if (pos <= m) modify(left[p] = copy(left[p], last[p]), l, m, pos, value);
            else modify(right[p] = copy(right[p], last[p]), m + 1, r, pos, value);
            st[p] = op(left[p] != -1 ? st[left[p]] : Tid, right[p] != -1 ? st[right[p]] : Tid);
        }
    }
    T query(int p, int l, int r, int ql, int qr)
    {
        if (p == -1 || r < ql || qr < l) return Tid;
        if (ql <= l && r <= qr) return st[p];
        int m = l + (r - l) / 2;
        T resl = query(left[p], l, m, ql, qr);
        T resr = query(right[p], m + 1, r, ql, qr);
        return op(resl, resr);
    }
public:
    PersistentST(int n, T Tid, auto op) : n(n), Tid(Tid), op(op) { root.push_back(create(0)); }
    int duplicate(int version)
    {
        root.push_back(copy(root[version], sz(root)));
        return sz(root) - 1;
    }
    void modify(int version, int pos, T value)
    {
        modify(root[version], 0, n - 1, pos, value);
    }
    T query(int version, int l, int r)
    {
        return query(root[version], 0, n - 1, l, r);
    }
};

template<int N>
struct Sieve
{
private:
    array<int, N + 1> lp, pr;
    int *b, *e;
public:
    constexpr Sieve() : lp{ 0 }, pr{ 0 }, b(&pr[0]), e(&pr[0])
    {
        for (int i = 2; i <= N; ++i)
        {
            if (lp[i] == 0) lp[i] = *(e++) = i;
            for (auto p : pr)
            {
                if (p > lp[i] || i * p > N || p == 0) break;
                lp[i * p] = p;
            }
        }
    }
    constexpr int operator[](int i) const { return lp[i]; }
    constexpr int* begin() const { return b; }
    constexpr int* end() const { return e; }
};

int main()
{ _
    constexpr int N = 1e7;
    constexpr ll MOD = 1e9 + 7;

    Sieve<N> sieve;

    int n; cin >> n;

    PersistentST<int> pst(n, 1, [&MOD](auto x, auto y){ return int(ll(x) * ll(y) % MOD); });

    vector stk(N + 1, vector(0, pair(0, 0)));

    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a;

        int idx = pst.duplicate(i);

        pst.modify(idx, i, a);

        while (a > 1)
        {
            int p = sieve[a], ppow = 1;
            while(sieve[a] == p) a /= p, ppow *= p;

            int prev = 1;
            while (not stk[p].empty() && ppow >= stk[p].back().first)
            {
                auto [f, j] = stk[p].back(); stk[p].pop_back();
                pst.modify(idx, j, pst.query(idx, j, j) / (f / prev));
                prev = f;
            }

            if (not stk[p].empty())
            {
                auto [f, j] = stk[p].back();
                pst.modify(idx, j, pst.query(idx, j, j) / (ppow / prev));
            }

            stk[p].emplace_back(ppow, i);
        }
    }

    int q; cin >> q;

    for (ll ans = 0LL; q > 0; --q)
    {
        ll x, y; cin >> x >> y;

        int l = int((x + ans) % n), r = int((y + ans) % n);
        if (r < l) swap(l, r);

        ans = pst.query(r + 1, l, r);

        cout << ans << endl;
    }

    exit(0);
}