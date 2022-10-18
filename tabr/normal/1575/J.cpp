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
    int h, w, k;
    cin >> h >> w >> k;
    vector<set<pair<int, int>>> st(h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int a;
            cin >> a;
            if (a != 2) {
                st[i].emplace(j, a);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        c--;
        for (int x = 0; x < h; x++) {
            while (true) {
                auto it = st[x].lower_bound(make_pair(c, -1));
                if (it == st[x].end()) {
                    break;
                }
                auto p = *it;
                if (p.first != c) {
                    break;
                }
                st[x].erase(p);
                if (p.second == 1) {
                    c++;
                } else {
                    c--;
                }
            }
        }
        cout << c + 1 << " ";
    }
    cout << '\n';
    return 0;
}