#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

#define x real
#define y imag

template<typename T>
T dot(complex<T> a, complex<T> b) { return (conj(a) * b).x(); }

template<typename T>
T cross(complex<T> a, complex<T> b) { return (conj(a) * b).y(); }

template<typename T>
bool cw(complex<T> a, complex<T> b, complex<T> c) {
    return cross(b - a, c - b) < 0;
}

template<typename T>
bool ccw(complex<T> a, complex<T> b, complex<T> c) {
    return cross(b - a, c - b) > 0;
}

template<typename T>
int up(complex<T> a) {
    if (a.x() == 0 && a.y() == 0) return 0;
    return a.y() > 0 || (a.y() == 0 && a.x() < 0) ? +1 : -1;
}

// sorts by atan2
template<typename T>
bool arg_cmp(complex<T> a, complex<T> b) {
    return up(a) == up(b) ? cross(a, b) > 0 : up(a) < up(b);
}

template<typename T>
bool lex_cmp(complex<T> a, complex<T> b) {
    return a.x() != b.x() ? a.x() < b.x() : a.y() < b.y();
}

template<typename T>
istream& operator>>(istream& in, complex<T>& p) {
    T x, y;
    in >> x >> y;
    p.x(x), p.y(y);
    return in;
}

// finds point x with dot(a, x) = t and dot(b, x) = s
template<typename T>
complex<T> intersection(complex<T> a, T t, complex<T> b, T s) {
    T div = cross(a, b);
    T x = cross(complex(t, s), complex<T>(a.y(), b.y())) / div;
    T y = -cross(complex(t, s), complex<T>(a.x(), b.x())) / div;
    return complex(x, y);
}

using ld = long double;

using cpx = complex<ll>;
using cpxd = complex<ld>;

const ld EPS = 1e-12;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll p, q;
    cin >> p >> q;

    struct Cmp {
        bool operator()(cpx a, cpx b) const { return arg_cmp(a, b); }
    };
    map<cpx, ld, Cmp> halfplanes;
    for (int i = 0; i < n; ++i) {
        cpx pt;
        cin >> pt;
        ll g = gcd(pt.x(), pt.y());
        pt /= g;
        if (not halfplanes.count(pt)) halfplanes[pt] = 1.0L / g;
        else halfplanes[pt] = min(halfplanes[pt], 1.0L / g);

    }
    halfplanes[cpx(-1, 0)] = 0.0;
    halfplanes[cpx(0, -1)] = 0.0;

    vector<cpxd> hull;
    vector<pair<cpxd, ld>> boundary;

    for (auto [p, t] : halfplanes) {
        cpxd pd(p.x(), p.y());
        if (not empty(boundary)) {
            while (not empty(hull) && dot(pd, hull.back()) >= t - EPS) {
                hull.pop_back();
                boundary.pop_back();
            }
            hull.push_back(intersection(pd, t, boundary.back().first, boundary.back().second));
        }
        boundary.emplace_back(pd, t);
    }

    assert(is_sorted(all(hull), arg_cmp<ld>));

    ld res = 0;
    for (auto pt : hull) {
        res = max(res, dot(cpxd(p, q), pt));
    }

    cout << setprecision(10) << fixed;
    cout << res << endl;

    exit(0);
}