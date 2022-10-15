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

const double EPS = 1e-9;

double solve()
{
    int n; cin >> n;
    double L; cin >> L;

    vector a(n + 2, 0.0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[n + 1] = L;
    n += 2;

    auto LEFT = [&](double t)
    {
        double v = 1.0, s = 0.0;
        for (int i = 0; i < n && t > EPS; ++i)
        {
            double d = min((a[i] - s) / v, t);
            if (d > EPS)
            {
                s += d * v;
                t -= d;
                v += 1.0;
            }
        }
        return s;
    };
    auto RIGHT = [&](double t)
    {
        double v = 1.0, s = L;
        for (int i = n - 1; i >= 0 && t > EPS; --i)
        {
            double d = min((s - a[i]) / v, t);
            if (d > EPS)
            {
                s -= d * v;
                t -= d;
                v += 1.0;
            }
        }
        return s;
    };

    double l = 0.0, r = L;
    for (int z = 0; z < 100; ++z)
    {
        double m = l + (r - l) / 2;
        if (LEFT(m) < RIGHT(m)) l = m;
        else r = m;
    }

    return l;
}

int main()
{ _
    int t; cin >> t;
    cout << setprecision(20) << fixed;
    while (t--) cout << solve() << endl;
    exit(0);
}