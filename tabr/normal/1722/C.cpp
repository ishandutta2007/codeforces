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
        cin >> n;
        map<string, int> cnt;
        vector<vector<string>> s(3, vector<string>(n));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> s[i][j];
                cnt[s[i][j]]++;
            }
        }
        for (int i = 0; i < 3; i++) {
            int t = 0;
            for (int j = 0; j < n; j++) {
                if (cnt[s[i][j]] == 1) {
                    t += 3;
                } else if (cnt[s[i][j]] == 2) {
                    t += 1;
                }
            }
            cout << t << " \n"[i == 2];
        }
    }
    return 0;
}