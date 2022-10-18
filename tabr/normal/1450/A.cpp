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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string a;
        cin >> n >> a;
        string b;
        string t = "trygub";
        vector<int> s(6);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 7; j++) {
                if (j == 6) {
                    b.push_back(a[i]);
                    break;
                }
                if (a[i] == t[j]) {
                    s[j]++;
                    break;
                }
            }
        }
        for (int i = 5; i >= 0; i--) {
            while (s[i]--) {
                b.push_back(t[i]);
            }
        }
        cout << b << '\n';
    }
    return 0;
}