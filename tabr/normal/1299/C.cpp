#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

using cpx = complex<double>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    ll s = 0, a = 0;
    vector<cpx> p(n + 1);
    rep(i, 0, n) {
        cin >> a;
        s += a;
        p[i + 1] = cpx(i + 1, s);
    }
    vector<cpx> d(n + 1);
    int k = 1;
    rep(i, 1, n + 1) {
        while (1 < k && imag((d[k - 1] - d[k - 2]) * conj(p[i] - d[k - 1])) >= 0) {
            k--;
        }
        d[k] = p[i];
        k++;
    }
    rep(i, 1, k) {
        int c = (d[i] - d[i - 1]).real();
        long double res = (d[i] - d[i - 1]).imag();
        res /= (long double)c;
        while (c--) cout << res << ' ';
    }
    cout << endl;
    return 0;
}