#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int a, int b) {  // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        vector<int> a(26);
        string y;
        for (char c : string(s.rbegin(), s.rend())) {
            if (!a[c - 'a']) {
                y += c;
            }
            a[c - 'a']++;
        }
        reverse(y.begin(), y.end());
        int m = (int) y.size();
        for (int i = 0; i < m; i++) {
            int j = y[i] - 'a';
            if (a[j] % (i + 1) != 0) {
                y.clear();
                break;
            }
            a[j] /= i + 1;
        }
        if (y.empty()) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                b[i] += a[y[j] - 'a'];
            }
        }
        vector<string> t(m);
        for (int i = 0, j = 0; i < m; i++) {
            t[i] = s.substr(j, b[i]);
            j += b[i];
        }
        // debug(t);
        int ok = 1;
        for (int i = 0; i < m; i++) {
            vector<int> d(26);
            for (char c : t[i]) {
                d[c - 'a']++;
            }
            for (int j = i; j < m; j++) {
                if (d[y[j] - 'a'] != a[y[j] - 'a']) {
                    ok = 0;
                }
            }
        }
        for (int i = 0; i < m - 1; i++) {
            string aa = t[i];
            string bb = t[i + 1];
            int id = 0;
            for (char c : bb) {
                while (id < (int) aa.size() && c != aa[id]) {
                    id++;
                }
                if (id == (int) aa.size()) {
                    id = -1;
                    break;
                }
                id++;
            }
            if (id == -1) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << t[0] << " " << y << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}