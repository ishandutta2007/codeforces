#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> a;
vector<bool> ok;
int lim;

inline void f(int i) {
    int l = 2 * i, r = 2 * i + 1;
    if (a[l] == 0 && a[r] == 0) {
        a[i] = 0;
    } else if (a[l] > a[r]) {
        a[i] = a[l];
        f(l);
    } else {
        a[i] = a[r];
        f(r);
    }
}

inline bool eval(int i) {
    int l = 2 * i, r = 2 * i + 1;
    if (a[l] == 0 && a[r] == 0) {
        int s = 1, c = 1;
        while (s * 2 <= i) {
            s *= 2;
            c++;
        }
        if (c == lim) {
            return ok[i] = false;
        }
    } else if (a[l] > a[r]) {
        return ok[i] = eval(l);
    } else {
        return ok[i] = eval(r);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int h, g;
        cin >> h >> g;
        int n = (1 << h) - 1;
        lim = g;
        a.assign(2 * n + 2, 0);
        ok.assign(n + 1, true);
        vector<pair<int, int>> p(n);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            if (ok[j]) {
                while (eval(j)) {
                    res.emplace_back(j);
                    f(j);
                    if (res.size() >= ((1 << h) - (1 << g))) break;
                }
            }
            if (res.size() >= ((1 << h) - (1 << g))) break;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i + 1];
        }
        cout << ans << '\n';
        for (int i : res) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}