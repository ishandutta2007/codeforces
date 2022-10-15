#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<int N>
struct F {
    int delay[N]{};
    F(int a = -1) {
        if (a == -1) return;
        fill(all(delay), 1);
        for (int x = 0; x < N; x += a) delay[x] += 1;
    }
    F operator+(const F& rhs) const {
        F res = *this;
        for (int x = 0; x < N; ++x)
            res.delay[x] += rhs.delay[(x + delay[x]) % N];
        return res;
    }
};


template<typename T>
struct M1 {
    using Type = T;
    inline const static T Id = T();
    static T op(const T& x, const T& y) { return x + y; }
};

template<typename Monoid>
struct SegmentTree {
private:
    using M = Monoid;
    using T = typename Monoid::Type;
    const int n;
    vector<T> st;
public:
    SegmentTree(int n) : n(n), st(2 * n, M::Id) { }
    SegmentTree(const vector<T>& a) : SegmentTree((int)size(a)) {
        for (int i = 0; i < n; ++i) st[n + i] = a[i];
        for (int i = n - 1; i > 0; --i)
            st[i] = M::op(st[i << 1], st[i << 1 | 1]);
    }
    void modify(int p, T value) {
        for (st[p += n] = value; p > 1; p >>= 1)
            st[p >> 1] = M::op(st[p & ~1], st[p | 1]);
    }
    T query(int l, int r) {
        T resl = M::Id, resr = M::Id;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = M::op(resl, st[l++]);
            if (r & 1) resr = M::op(st[--r], resr);
        }
        return M::op(resl, resr);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    constexpr int lmax = 60;
    SegmentTree<M1<F<lmax>>> st(n);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        st.modify(i, F<lmax>(a));
    }

    int q;
    cin >> q;

    for (int z = 0; z < q; ++z) {
        char c;
        cin >> c;

        if (c == 'A') {
            int i, j;
            cin >> i >> j;
            --i, --j;
            int res = st.query(i, j - 1).delay[0];
            cout << res << endl;
        }
        else {
            int i, a;
            cin >> i >> a;
            --i;
            st.modify(i, F<lmax>(a));
        }
    }

    exit(0);
}