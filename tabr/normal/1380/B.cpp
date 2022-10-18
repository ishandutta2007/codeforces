#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        string t = "RSP";
        string u = "PRS";
        vector<int> a(3);
        for (char c : s) {
            for (int i = 0; i < 3; i++) {
                if (c == t[i]) {
                    a[i]++;
                }
            }
        }
        int mx = *max_element(a.begin(), a.end());
        for (int i = 0; i < 3; i++) {
            if (mx == a[i]) {
                cout << string(s.size(), u[i]) << '\n';
                break;
            }
        }
    }
    return 0;
}