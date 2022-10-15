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
istream& operator>>(istream& in, complex<T>& p) {
    T x, y;
    in >> x >> y;
    p.x(x), p.y(y);
    return in;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    using cpx = complex<ll>;

    cpx s, t;
    cin >> s >> t;

    int n;
    cin >> n;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        cpx p;
        cin >> p;
        ll h;
        cin >> h;
        res += (dot(s, p) < -h) ^ (dot(t, p) < -h);
    }

    cout << res << endl;

    exit(0);
}