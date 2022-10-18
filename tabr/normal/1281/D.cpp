#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        string pp, aa;
        rep(i, 0, c) {
            pp += 'P';
            aa += 'A';
        }
        vector<string> s(r);
        bool allA = true, allP = true;
        rep(i, 0, r) {
            cin >> s[i];
            if (s[i] != pp)
                allP = false;
            if (s[i] != aa)
                allA = false;
        }
        if (allA) {
            cout << 0 << endl;
            continue;
        } else if (allP) {
            cout << "MORTAL" << endl;
            continue;
        }

        vector<int> rx(r, 1e5), cx(c, 1e5);
        rep(i, 0, r) {
            if (s[i][0] != s[i][c - 1]) {
                rx[i] = 1;
            } else if (s[i][0] == 'A') {
                rx[i] = 0;
                rep(j, 1, c) if (s[i][j] == 'P') {
                    rx[i] = 1;
                    break;
                }
            } else {
                rep(j, 1, c) if (s[i][j] == 'A') {
                    rx[i] = 2;
                    break;
                }
            }
        }
        rep(i, 0, c) {
            if (s[0][i] != s[r - 1][i]) {
                cx[i] = 1;
            } else if (s[0][i] == 'A') {
                cx[i] = 0;
                rep(j, 1, r) if (s[j][i] == 'P') {
                    cx[i] = 1;
                    break;
                }
            } else {
                rep(j, 1, r) if (s[j][i] == 'A') {
                    cx[i] = 2;
                    break;
                }
            }
        }
        int ans = 1e5;
        rep(i, 0, r) {
            int x = rx[i] + 2;
            if (i == 0 || i == r - 1)
                x--;
            ans = min(ans, x);
        }
        rep(i, 0, c) {
            int x = cx[i] + 2;
            if (i == 0 || i == c - 1)
                x--;
            ans = min(ans, x);
        }
        cout << ans << endl;
    }

    return 0;
}