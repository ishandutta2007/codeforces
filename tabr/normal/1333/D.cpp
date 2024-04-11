#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> st;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'R' && s[i + 1] == 'L') {
            st.emplace_back(i);
        }
    }
    vector<vector<int>> ans;
    int m = 0;
    for (int q = 0; q < k; q++) {
        if (st.empty()) {
            break;
        }
        m += (int)st.size();
        ans.emplace_back(st);
        for (int i : st) {
            s[i] = 'L';
            s[i + 1] = 'R';
        }
        vector<int> nst;
        for (int i : st) {
            if (i != 0 && s[i - 1] == 'R') {
                nst.emplace_back(i - 1);
            }
            if (i + 2 < n && s[i + 2] == 'L') {
                nst.emplace_back(i + 1);
            }
        }
        sort(nst.begin(), nst.end());
        nst.resize(unique(nst.begin(), nst.end()) - nst.begin());
        swap(st, nst);
    }
    if (!st.empty() || m < k) {
        cout << -1 << '\n';
    } else {
        k -= (int)ans.size();
        for (auto v : ans) {
            if (k == 0) {
                cout << v.size() << " ";
                for (int i : v) {
                    cout << i + 1 << " ";
                }
                cout << '\n';
            } else if (k + 1 >= (int)v.size()) {
                for (int i : v) {
                    cout << 1 << " " << i + 1 << '\n';
                }
                k -= (int)v.size() - 1;
            } else {
                for (int i = 0; i < k; i++) {
                    cout << 1 << " " << v[i] + 1 << '\n';
                }
                cout << (int)v.size() - k << " ";
                for (int i = k; i < (int)v.size(); i++) {
                    cout << v[i] + 1 << " ";
                }
                cout << '\n';
                k = 0;
            }
        }
    }
    return 0;
}