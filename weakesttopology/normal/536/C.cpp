#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
T gcd(T a, T b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        a %= b;
        swap(a, b);
    }
    assert(a);
    return a;
}

#define x real
#define y imag

template<typename T>
using Segment = array<complex<T>, 2>;

// represents points p with dot(Line.first, p) = Line.second
template<typename T>
using Line = pair<complex<T>, T>;

template<typename T>
T dot(complex<T> a, complex<T> b) { return (conj(a) * b).x(); }

template<typename T>
T cross(complex<T> a, complex<T> b) { return (conj(a) * b).y(); }

template<typename T>
complex<T> normalized(complex<T> a) { return a / gcd<T>(a.x(), a.y()); }

template<typename T>
bool cw(complex<T> a, complex<T> b, complex<T> c) {
    return cross(normalized(b - a), normalized(c - b)) < 0;
}

template<typename T>
bool ccw(complex<T> a, complex<T> b, complex<T> c) { return cross(b - a, c - b) > 0; }

template<typename T>
istream& operator>>(istream& in, complex<T>& p) {
    int x, y;
    in >> x >> y;
    p.x(x), p.y(y);
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, complex<T> p) {
    return out << p.x() << " " << p.y();
}

template<typename T>
bool lex_cmp(complex<T> a, complex<T> b) {
    return a.x() != b.x() ? a.x() < b.x() : a.y() < b.y();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    using T = __int128;
    using cpx = complex<T>;

    int n;
    cin >> n;

    vector<cpx> pts(n);
    vector<T> a(n);

    struct MapCmp {
        bool operator()(cpx a, cpx b) const { return lex_cmp(a, b); }
    };
    map<cpx, int, MapCmp> Id;
    vector<int> I;

    for (int i = 0; i < n; ++i) {
        cin >> pts[i];
        a[i] = pts[i].x() * pts[i].y();
        if (not Id.count(pts[i])) {
            Id[pts[i]] = i;
            I.push_back(i);
        }
    }

    sort(all(I), [&](int i, int j){ return lex_cmp(a[j] * pts[i], a[i] * pts[j]); });

    vector<int> B(n);
    B[0] = I[0];

    int k = 1;
    for (int j = 1; j < (int)size(I); ++j) {
        int i = I[j];
        while (k > 1 && cw(
                    pts[B[k - 2]] * a[i] * a[B[k - 1]],
                    pts[B[k - 1]] * a[i] * a[B[k - 2]],
                    pts[i] * a[B[k - 1]] * a[B[k - 2]]
                    )) --k;
        if (a[i] * pts[B[k - 1]].y() > a[B[k - 1]] * pts[i].y()) B[k++] = i;
    }

    vector<bool> win(n, false);
    for (int i = 0; i < k; ++i) win[B[i]] = true;

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (win[Id[pts[i]]]) ans.push_back(i);
    }

    int r = (int)size(ans);
    for (int i = 0; i < r; ++i) {
        cout << ans[i] + 1 << "\n "[i + 1 < r];
    }

    exit(0);
}