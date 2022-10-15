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

int main()
{ _
    constexpr int N = 1e5, M = N / 2;

    int n; cin >> n;

    vector<tuple<int, int, int>> H, V;

    for (int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        x1 += M, x2 += M, y1 += M, y2 += M;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        if (x1 == x2) V.emplace_back(x1, y1, y2);
        if (y1 == y2) H.emplace_back(y1, x1, x2);
    }

    sort(all(V));

    ll ans = 0LL;

    BIT<int, F1<int>> bit(N + 1);

    for (auto [x, low, high] : V)
    {
        vector<tuple<int, int, int>> Ev;

        for (auto [y, l, r] : H)
            if (low <= y && y <= high && l <= x && x <= r)
            {
                Ev.emplace_back(l, -INF, y);
                Ev.emplace_back(r, INF, y);
            }

        for (auto [xprv, lowprv, highprv] : V)
        {
            if (xprv == x) break;
            Ev.emplace_back(xprv, lowprv, highprv);
        }

        sort(all(Ev));

        for (auto [xprv, lowprv, highprv] : Ev)
        {
            if (abs(lowprv) == INF)
            {
                bit.update(highprv, (lowprv < 0 ? 1 : -1));
            }
            else
            {
                int s = bit.query(lowprv, highprv);
                ans += s * (s - 1) / 2;
            }
        }
    }

    cout << ans << endl;

    exit(0);
}