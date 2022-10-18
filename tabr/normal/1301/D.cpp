#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (4 * n * m - 2 * n - 2 * m < k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int cnt = 0;
    vector<int> a;
    vector<string> b;
    if (m == 1) {
        if (k <= n - 1) {
            cout << 1 << endl;
            cout << k << " D" << endl;
        } else {
            cout << 2 << endl;
            cout << n - 1 << " D" << endl;
            cout << k + 1 - n << " U" << endl;
        }
        return 0;
    }
    rep(i, 0, n - 1) {
        if (cnt + m - 1 <= k) {
            cnt += m - 1;
            a.emplace_back(m - 1);
            b.emplace_back("R");
            if (cnt == k) break;
        } else {
            a.emplace_back(k - cnt);
            b.emplace_back("R");
            cnt = k;
            break;
        }
        if (cnt + 1 <= k) {
            cnt++;
            a.emplace_back(1);
            b.emplace_back("D");
            if (cnt == k) break;
        }
        if (cnt + 3 * (m - 1) <= k) {
            cnt += 3 * (m - 1);
            a.emplace_back(m - 1);
            b.emplace_back("ULD");
        } else {
            if (cnt + 3 <= k) {
                a.emplace_back((k - cnt) / 3);
                b.emplace_back("ULD");
                cnt += (k - cnt) / 3 * 3;
            }
            if (cnt == k - 1) {
                a.emplace_back(1);
                b.emplace_back("U");
                cnt = k;
            } else if (cnt == k - 2) {
                a.emplace_back(1);
                b.emplace_back("UL");
                cnt = k;
            }
        }
        if (cnt == k) break;
    }
    if (cnt != k) {
        a.emplace_back(min(k - cnt, m - 1));
        b.emplace_back("R");
        cnt += a.back();
        if (k != cnt) {
            a.emplace_back(min(k - cnt, m - 1));
            b.emplace_back("L");
            cnt += a.back();
        }
        if (k != cnt) {
            a.emplace_back(min(k - cnt, n - 1));
            b.emplace_back("U");
        }
    }
    cout << a.size() << endl;
    rep(i, 0, a.size()) {
        cout << a[i] << ' ' << b[i] << endl;
    }
    return 0;
}