#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

map <pair<int, int>, bool> r, u;

int main () {
    int T = read();
    while (T--) {
        r.clear(), u.clear();
        string x;
        cin >> x;
        int s = x.size();
        int i, j, ans = 0;
        int X = 0, Y = 0;
        for (i = 0; i < s; i++) {
            if (x[i] == 'N') {
                if (u[make_pair(X, Y)]) ans++;
                else ans += 5, u[make_pair(X, Y)] = true;
                Y++;
            }
            if (x[i] == 'S') {
                Y--;
                if (u[make_pair(X, Y)]) ans++;
                else ans += 5, u[make_pair(X, Y)] = true;
            }
            if (x[i] == 'W') {
                X--;
                if (r[make_pair(X, Y)]) ans++;
                else ans += 5, r[make_pair(X, Y)] = true;    
            }
            if (x[i] == 'E') {
                if (r[make_pair(X, Y)]) ans++;
                else ans += 5, r[make_pair(X, Y)] = true;    
                X++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}