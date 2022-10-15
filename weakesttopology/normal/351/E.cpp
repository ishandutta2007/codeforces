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

template<typename T>
struct F1
{
    static constexpr T id = 0;
    static T op(const T& x, const T& y) { return x + y; }
    static T inv(const T& x) { return -x; }
};

template<typename T, typename F>
class BIT
{
private:
    int b(int p) { return p & (-p); }
    const int n;
    vector<T> ft;
    T query(int p)
    {
        T res = F::id;
        for (int i = p; i >= 1; i -= b(i)) res = F::op(ft[i], res);
        return res;
    }
public:
    BIT(int n) : n(n) { ft.assign(n + 1, F::id); }
    BIT(const vector<T>& a) : BIT(size(a), F::id)
    {
        for (int i = 1; i <= n; ++i) ft[i] = F::op(ft[i - 1], a[i - 1]);
        for (int i = n; i >= 1; --i) ft[i] = F::op(F::inv(ft[i - b(i)]), ft[i]);
    }
    T query(int l, int r) { return F::op(F::inv(query(l)), query(r + 1)); }
    void update(int p, T value)
    {
        for (int i = p + 1; i <= n; i += b(i)) ft[i] = F::op(ft[i], value);
    }
};

int compress(auto& a)
{
    auto b = a;
    sort(all(b));
    b.erase(unique(all(b)), end(b));
    for (auto& x : a)
    {
        auto iter = lower_bound(all(b), x);
        x = (int)distance(begin(b), iter);
    }
    return size(b);
}

int main()
{ _
    int n; cin >> n;

    vector p(n, 0);

    for (auto& x : p) { cin >> x; x = abs(x); }

    int m = compress(p);

    BIT<int, F1<int>> bitprefix(m), bitsuffix(m);

    for (auto x : p) bitsuffix.update(x, 1);

    ll ans = 0;

    for (auto x : p)
    {
        bitprefix.update(x, +1), bitsuffix.update(x, -1);

        int smallprefix = x > 0 ? bitprefix.query(0, x - 1) : 0;
        int smallsuffix = x > 0 ? bitsuffix.query(0, x - 1) : 0;

        // x *= smallprefix >= smallsuffix ? 1 : -1;

        ans += min(smallprefix, smallsuffix);
    }

    cout << ans << endl;

    exit(0);
}