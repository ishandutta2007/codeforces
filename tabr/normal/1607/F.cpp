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
        int h, w;
        cin >> h >> w;
        vector<int> g(h * w);
        vector<string> s(h);
        for (int i = 0; i < h; i++) {
            cin >> s[i];
            for (int j = 0; j < w; j++) {
                int x = i;
                int y = j;
                if (s[i][j] == 'U') {
                    x--;
                } else if (s[i][j] == 'D') {
                    x++;
                } else if (s[i][j] == 'L') {
                    y--;
                } else {
                    y++;
                }
                if (x == -1 || x == h || y == -1 || y == w) {
                    g[i * w + j] = i * w + j;
                } else {
                    g[i * w + j] = x * w + y;
                }
            }
        }
        vector<int> d(h * w, -1);
        vector<int> mp(h * w, -1);
        int sz = 0;
        auto dfs = [&](int r) {
            vector<int> st;
            int v = r;
            while (true) {
                int to = g[v];
                if (d[to] != -1) {
                    int res = d[to];
                    st.emplace_back(v);
                    while (!st.empty()) {
                        res++;
                        d[st.back()] = res;
                        st.pop_back();
                    }
                    break;
                }
                if (mp[v] != -1) {
                    d[v] = sz - mp[v];
                    int res = d[v];
                    while (st.back() != v) {
                        d[st.back()] = res;
                        st.pop_back();
                    }
                    st.pop_back();
                    while (!st.empty()) {
                        res++;
                        d[st.back()] = res;
                        st.pop_back();
                    }
                    break;
                }
                mp[v] = sz;
                sz++;
                st.emplace_back(v);
                v = to;
                continue;
            }
        };
        for (int v = 0; v < h * w; v++) {
            if (d[v] != -1) {
                continue;
            }
            sz = 0;
            dfs(v);
        }
        debug(d);
        int z = (int) (max_element(d.begin(), d.end()) - d.begin());
        cout << z / w + 1 << " " << z % w + 1 << " " << d[z] << '\n';
    }
    return 0;
}