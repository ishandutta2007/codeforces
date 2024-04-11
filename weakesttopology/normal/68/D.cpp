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

int main()
{ _
    int h, q; cin >> h >> q;

    map<int, int> tr;

    auto get = [&](int v) { return tr.count(v) ? tr[v] : 0; };

    auto add = [&](int v, int add)
    {
        while (v > 0) { tr[v] += add; v >>= 1; }
    };

    function<double(int, double, int)> solve = [&](int v, double p, int prevmax)
    {
        if (v >= (1 << h)) return p * get(v);

        int sub = get(v), subl = get(v << 1), subr = get(v << 1 | 1);

        double ans = 0.0;

        p /= 2;

        if (int x = max(sub - subl, prevmax); subl <= x)
            ans += p * x;
        else
            ans += solve(v << 1, p, x);

        if (int x = max(sub - subr, prevmax); subr <= x)
            ans += p * x;
        else
            ans += solve(v << 1 | 1, p, x);

        return ans;
    };

    cout << setprecision(20) << fixed;

    for (int z = 0; z < q; ++z)
    {
        string op; cin >> op;
        if (op == "add")
        {
            int v, e; cin >> v >> e;
            add(v, e);
        }
        else
        {
            double ans = solve(1, 1.0, 0);
            cout << ans << endl;
        }
    }

    exit(0);
}