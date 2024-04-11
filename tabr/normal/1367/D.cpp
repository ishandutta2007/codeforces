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
        int m;
        cin >> s >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int n = s.size();
        vector<int> c(m, -1), cnt(1);
        int nxt = 1;
        for (int i = 0; i < m; i++) {
            if (b[i] == 0) {
                c[i] = 0;
                cnt[0]++;
            }
        }
        while (true) {
            bool done = true;
            for (int i = 0; i < m; i++) {
                if (c[i] == -1) {
                    done = false;
                    break;
                }
            }
            if (done) {
                break;
            }
            cnt.emplace_back(0);
            for (int i = 0; i < m; i++) {
                if (c[i] != -1) {
                    continue;
                }
                int all = 0;
                for (int j = 0; j < m; j++) {
                    if (c[j] < nxt && c[j] != -1) {
                        all += abs(i - j);
                    }
                }
                if (all == b[i]) {
                    c[i] = nxt;
                    cnt[nxt]++;
                }
            }
            nxt++;
        }
        string ans(m, ' ');
        int id = 0;
        for (char a = 'z'; a >= 'a'; a--) {
            int all = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == a) {
                    all++;
                }
            }
            if (all >= cnt[id]) {
                for (int i = 0; i < m; i++) {
                    if (c[i] == id) {
                        ans[i] = a;
                    }
                }
                id++;
                if (nxt == id) {
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}