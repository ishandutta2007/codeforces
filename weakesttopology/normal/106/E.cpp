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

template<typename... Args>
auto ternary_search(auto l, auto r, auto eps, auto&& f, Args... args)
{
    using T = decltype(l);
    while (r - l > eps)
    {
        T m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (f(m1, args...) > f(m2, args...)) l = m1;
        else r = m2;
    }
    T c = l;
    if (is_floating_point<T>::value)
        return pair(f(c, args...), c);
    for (T x = c + 1; x <= r; ++x)
        if (f(x, args...) < f(c, args...)) c = x;
    return pair(f(c, args...), c);
}

int main()
{ _
    int n; cin >> n;

    vector X(n, 0.0), Y(n, 0.0), Z(n, 0.0);

    for (int i = 0; i < n; ++i) cin >> X[i] >> Y[i] >> Z[i];

    using T = double;

    const T L = -1e4, R = 1e4, EPS = 1e-9;

    auto sq = [](T w) { return w * w; };

    auto fz = [&](T z, T y, T x)
    {
        T res = 0.0;
        for (int i = 0; i < n; ++i)
            res = max(res, sq(abs(X[i] - x)) + sq(abs(Y[i] - y)) + sq(abs(Z[i] - z)));
        return res;
    };

    auto fy = [&](T y, T x)
    {
        return ternary_search(L, R, EPS, fz, y, x).first;
    };

    auto fx = [&](T x)
    {
        return ternary_search(L, R, EPS, fy, x).first;
    };

    T xans = ternary_search(L, R, EPS, fx).second;
    T yans = ternary_search(L, R, EPS, fy, xans).second;
    T zans = ternary_search(L, R, EPS, fz, yans, xans).second;

    cout << setprecision(20) << fixed;
    cout << xans << " " << yans << " " << zans << endl;

    exit(0);
}