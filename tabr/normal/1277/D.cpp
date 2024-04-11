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
        int n;
        cin >> n;
        int s0 = 0, s1 = 0;
        int t01 = 0, t10 = 0;
        int ta01 = 0, ta10 = 0;
        set<string> st;
        map<string, int> mp;
        vector<string> t;
        rep(i, 0, n) {
            string s;
            cin >> s;
            if (s[0] != s[s.size() - 1]) {
                st.insert(s);
                t.emplace_back(s);
                mp[s] = i + 1;
                if (s[0] == '0') {
                    t01++;
                } else {
                    t10++;
                }
            } else if (s[0] == '0')
                s0++;
            else
                s1++;
        }
        if (t.size() == 0) {
            if (s0 * s1) {
                cout << -1 << endl;
                continue;
            } else {
                cout << 0 << endl;
                cout << endl;
                continue;
            }
        }
        vector<int> a10, a01;
        rep(i, 0, t.size()) {
            string x = t[i];
            reverse(t[i].begin(), t[i].end());
            if (st.find(t[i]) == st.end()) {
                if (t[i][0] == '0') {
                    ta10++;
                    a10.emplace_back(mp[x]);
                } else {
                    ta01++;
                    a01.emplace_back(mp[x]);
                }
            }
        }
        int d = abs(t01 - t10) / 2;
        if (d == 0) {
            cout << 0 << endl;
            cout << endl;
            continue;
        }
        if (t01 > t10) {
            if (ta01 >= d) {
                cout << d << endl;
                rep(i, 0, d) cout << a01[i] << ' ';
                cout << endl;
            } else {
                cout << -1 << endl;
                continue;
            }
        } else {
            if (ta10 >= d) {
                cout << d << endl;
                rep(i, 0, d) cout << a10[i] << ' ';
                cout << endl;
            } else {
                cout << -1 << endl;
                continue;
            }
        }
    }
    return 0;
}