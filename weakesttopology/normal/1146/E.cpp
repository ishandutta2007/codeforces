#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int log(int x)
{
    return __builtin_clz(1) - __builtin_clz(x);
}

template<typename T>
struct SegmentTree
{
private:
    const int n, h;
    const T Tid;
    const function<void(T&, T)> apply;
    vector<T> st;
public:
    SegmentTree(int n, T Tid, auto apply) : n(n), h(log(n)), Tid(Tid), apply(apply)
    {
        st.assign(2 * n, Tid);
    }
    void push(int p)
    {
        for (int s = h; s > 0; --s)
        {
            int q = p >> s;
            apply(st[q << 1], st[q]), apply(st[q << 1 | 1], st[q]);
            st[q] = Tid;
        }
    }
    void update(int l, int r, T add)
    {
        for (push(l += n), push((r += n + 1) - 1); l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) apply(st[l++], add);
            if (r & 1) apply(st[--r], add);
        }
    }
    vector<T> get()
    {
        for (int p = 1; p < n; ++p)
        {
            apply(st[p << 1], st[p]), apply(st[p << 1 | 1], st[p]);
            st[p] = Tid;
        }
        return vector(n + all(st));
    }
};

int main()
{ _
    int n, q; cin >> n >> q;

    vector a(n, 0);

    for (auto& x : a) cin >> x;

    using flipflop = pair<int, int>;

    auto apply = [&](flipflop& x, flipflop y)
    {
        auto& [state, type] = x;
        if (y.second == 0) x = y; // y is assignment
        else if (y.first == 1) state ^= 1;
    };
    flipflop Id = { 0, 1 };

    const int N = 2e5 + 1, mid = 1e5;

    auto idx = [&](int x) { return mid + x; };

    SegmentTree st(N, Id, apply);

    for (int z = 0; z < q; ++z)
    {
        char c; cin >> c;
        int x; cin >> x;

        if (c == '>') // a > x
        {
            st.update(0, idx(-abs(x) - 1), flipflop(0, 0));
            st.update(idx(+abs(x) + 1), N - 1, flipflop(1, 0));
            if (x < 0)
            {
                st.update(idx(-abs(x) + 1), idx(+abs(x) - 1), flipflop(1, 1));
                st.update(idx(x), idx(x), flipflop(0, 0));
                st.update(idx(-x), idx(-x), flipflop(1, 0));
            }
        }
        else // a < x
        {
            if (x >= 0)
            {
                st.update(idx(x), N - 1, flipflop(0, 0));
                st.update(idx(-x + 1), idx(x - 1), flipflop(1, 1));
                st.update(0, idx(-x), flipflop(1, 0));
            }
            else
            {
                st.update(0, idx(x - 1), flipflop(1, 0));
                st.update(idx(-x + 1), N - 1, flipflop(0, 0));
            }
        }
    }

    auto flip = st.get();

    for (auto& x : a)
    {
        auto [state, type] = flip[idx(x)];
        if (state) x *= -1;
    }

    for (auto x : a) cout << x << " ";
    cout << endl;

    exit(0);
}