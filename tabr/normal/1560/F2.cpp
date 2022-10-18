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
        int n, k;
        cin >> n >> k;
        // n = get_rand(100, 1000);
        // k = 2;
        cerr << n << " " << k << " ";
        vector<int> a;
        while (n != 0) {
            a.emplace_back(n % 10);
            n /= 10;
        }
        int m = (int) a.size();
        vector<int> c(m, 1);
        for (int i = 1; i < m; i++) {
            c[i] = c[i - 1] * 10;
        }
        reverse(a.begin(), a.end());
        reverse(c.begin(), c.end());
        if (k == 1) {
            int x = accumulate(c.begin(), c.end(), 0) * a[0];
            for (int i = 0; i < m; i++) {
                n += c[i] * a[i];
            }
            if (x >= n) {
            } else {
                x += accumulate(c.begin(), c.end(), 0);
            }
            cout << x << '\n';
            continue;
        }
        vector<int> b(10);
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (!b[a[i]]) {
                b[a[i]] = 1;
                cnt++;
            }
            ans += a[i] * c[i];
            if (cnt <= k - 2) {
                continue;
            }
            int pref = ans;
            ans = (int) 2e9;
            for (int add = 0; add < 10; add++) {
                if (b[add]) {
                    continue;
                }
                int t = pref;
                b[add] = 1;
                int over = 0;
                for (int j = i + 1; j < m; j++) {
                    if (!over) {
                        over = -1;
                        int s = t;
                        for (int l = a[j]; l < 10; l++) {
                            if (b[l]) {
                                if (l == a[j]) {
                                    over = 0;
                                } else {
                                    over = 1;
                                }
                                t += l * c[j];
                                break;
                            }
                        }
                        if (over == -1) {
                            break;
                        } else if (over == 0 && a[j] != 9) {
                            for (int l = a[j] + 1; l < 10; l++) {
                                if (b[l]) {
                                    s += l * c[j];
                                    break;
                                }
                                if (l == 9) {
                                    s = -1;
                                }
                            }
                            if (s != -1) {
                                for (int l = 0; l < 10; l++) {
                                    if (b[l]) {
                                        for (int jj = j + 1; jj < m; jj++) {
                                            s += l * c[jj];
                                        }
                                        break;
                                    }
                                }
                                ans = min(ans, s);
                            }
                        }
                    } else {
                        for (int l = 0; l < 10; l++) {
                            if (b[l]) {
                                t += l * c[j];
                                break;
                            }
                        }
                    }
                }
                if (over != -1) {
                    ans = min(ans, t);
                }
                b[add] = 0;
            }
            break;
        }
        cout << ans << '\n';
    }
    return 0;
}