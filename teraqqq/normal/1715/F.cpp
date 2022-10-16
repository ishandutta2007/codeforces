#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

using ld = long double;

ld ask(vector<pi> k) {
    cout << "? " << k.size() << '\n';
    for (auto [x, y] : k) cout << x << " " << y << '\n';
    cout.flush();

    ld x; cin >> x;
    return x;
}

ld ask(vector<pair<ld, ld>> k) {
    cout << "? " << k.size() << '\n';
    cout << setprecision(15) << fixed;
    for (auto [x, y] : k) cout << x << " " << y << '\n';
    cout.flush();

    ld x; cin >> x;
    return x;
}

const int N = 100;
const int M = N/3+4;
const ld EPS = 1e-12;

void solve() {
    int n, m; cin >> n >> m;
    vector<pi> r1 { {N, -1}, { 0, -1} };
    for (int i = 0; i <= N; ++i) {
        if (i % 3 == 0) {
            if (i != 0) r1.emplace_back(i, 0);
            r1.emplace_back(i, m);
        } else if (i % 3 == 1) {
            r1.emplace_back(i, m);
            if (i != N) r1.emplace_back(i, 0);
        }
    }

    ld sx_1 = ask(r1);
    for (auto& [x, y] : r1) x++;
    ld sx_2 = ask(r1);

    ld x0 = (sx_1 < EPS ? 2 - sx_2 : sx_2 < EPS ? sx_1 - 1 : 1 - sx_1);

    cerr << "x0 = " << x0 << endl;

    vector<pair<ld, ld>> r2 { {0, -1} };

    for (int i = 0; i < M; ++i) {
        const ld x1 = 3 * i + x0;
        const ld x2 = 3 * i + x0 + 1;
        r2.emplace_back(x1, 0);
        r2.emplace_back(x2, m);
        r2.emplace_back(x2, 0);
    }

    ld sy = ask(r2);
    ld y = ((1 - sy) * 2 * m - 1) / 2;

    vector<pair<ld, ld>> r3{ { 0, y }, { 0, y+1 }, { n, y } };
    ld sx = ask(r3);
    ld x = ((1 - sx) * 2 * n - 1) / 2;

    cout << "! " << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}