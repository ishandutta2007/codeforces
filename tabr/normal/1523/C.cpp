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
        vector<int> c(1, 1);
        auto pr = [&]() {
            for (int i = 0; i < (int) c.size(); i++) {
                if (i) {
                    cout << ".";
                }
                cout << c[i];
            }
            cout << '\n';
        };
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (i == 0) {
                pr();
                continue;
            }
            if (a == 1) {
                c.emplace_back(1);
                pr();
                continue;
            }
            while (c.back() != a - 1) {
                c.pop_back();
            }
            c.back() = a;
            pr();
        }
    }
    return 0;
}