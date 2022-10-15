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
T slope(complex<T> p, complex<T> q) {
    complex<T> d = q - p;
    return d.y() / d.x();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    partial_sum(all(a), begin(a));

    vector<array<ll, 2>> lines;
    lines.push_back({0, 0});
    for (int i = 0; i < n; ++i) {
        lines.push_back({+(i + 1), +a[i]});
    }
    int N = (int)size(lines);

    using cpx = complex<double>;

    auto f = [&](int i, double x) { return (double)lines[i][0] * x + (double)lines[i][1]; };
    auto intersection = [&](int i, int j) {
        assert(i != j);
        double x = double(lines[j][1] - lines[i][1]) / double(lines[i][0] - lines[j][0]);
        return cpx(x, f(i, x));
    };

    vector<cpx> upper, lower;
    stack<int> stk;
    for (int i = 0; i < N; ++i) {
        while (not empty(upper) && upper.back().y() <= f(i, upper.back().x())) {
            upper.pop_back();
            stk.pop();
        }
        if (not empty(stk)) upper.push_back(intersection(i, stk.top()));
        stk.push(i);
    }
    stk = stack<int>();
    for (int i = 0; i < N; ++i) {
        while (not empty(lower) && lower.back().y() >= f(i, lower.back().x())) {
            lower.pop_back();
            stk.pop();
        }
        if (not empty(stk)) lower.push_back(intersection(i, stk.top()));
        stk.push(i);
    }

    reverse(all(lower));

    upper.insert(begin(upper), cpx(-INF, f(0, -INF)));
    upper.insert(end(upper), cpx(+INF, f(N - 1, +INF)));

    lower.insert(begin(lower), cpx(-INF, f(N - 1, -INF)));
    lower.insert(end(lower), cpx(+INF, f(0, +INF)));

    double ans = 1e300;
    for (int t = 0; t < 2; ++t, swap(upper, lower)) {
        int k = (int)size(upper), j = 0;
        for (auto pt : lower) {
            while (j + 1 < k && upper[j + 1].x() <= pt.x()) ++j;
            if (j == k - 1) break;
            cpx d = upper[j + 1] - upper[j]; 
            double alpha = (pt - upper[j]).x() / d.x();
            ans = min(ans, abs((upper[j] + alpha * d - pt).y()));
        }
    }

    cout << setprecision(10) << fixed;
    cout << ans << endl;

    exit(0);
}