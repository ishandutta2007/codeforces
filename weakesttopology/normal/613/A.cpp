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

template<typename T, typename... Args>
auto ternary_search(T l, T r, T eps, auto&& f, Args... args)
{
    while (r - l > eps)
    {
        T m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1, args...) > f(m2, args...)) l = m1;
        else r = m2;
    }
    T c = l;
    return pair(f(c, args...), c);
}

int main()
{ _
    int n; cin >> n;

    double xp, yp; cin >> xp >> yp;

    vector x(n, 0.0), y(n, 0.0);

    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    auto sq = [](auto x) { return x * x; };

    auto f = [&](double t, int i)
    {
        int j = (i + 1) % n;

        double xm = t * x[i] + (1 - t) * x[j];
        double ym = t * y[i] + (1 - t) * y[j];

        return sq(xp - xm) + sq(yp - ym);
    };

    double maxradius = 0.0, minradius = 1e300;

    for (int i = 0; i < n; ++i)
    {
        maxradius = max(maxradius, sq(x[i] - xp) + sq(y[i] - yp));
        minradius = min(minradius, ternary_search<double, int>(0, 1, 1e-6, f, i).first);
    }

    double ans = acos(-1) * (maxradius - minradius);

    cout << setprecision(20) << fixed;
    cout << ans << endl;

    exit(0);
}