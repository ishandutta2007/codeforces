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

void solve()
{
    int n, q; cin >> n >> q;

    vector a(n, 0);

    for (auto& x : a) cin >> x;

    vector pretty(0, 0LL);

    function<void(int, int)> build = [&](int l, int r)
    {
        int xmin = INF, xmax = -INF;

        ll sum = 0LL;

        for (int i = l; i <= r; sum += a[i++])
            xmin = min(xmin, a[i]), xmax = max(xmax, a[i]);

        pretty.push_back(sum);

        if (l == r || xmin == xmax) return;

        int mid = (xmin + xmax) / 2;

        auto pred = [&mid](int x){ return x <= mid; };

        auto iter = partition(begin(a) + l, begin(a) + r + 1, pred);

        int m = (int)distance(begin(a), iter) - 1;

        build(l, m), build(m + 1, r);
    };

    build(0, n - 1);

    sort(all(pretty));

    for (int z = 0; z < q; ++z)
    {
        ll s; cin >> s;

        string ans = binary_search(all(pretty), s) ? "Yes" : "No";

        cout << ans << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}