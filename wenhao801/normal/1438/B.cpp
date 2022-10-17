#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

map <int, bool> vis;
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int main () {
    int T = read();
    while (T--) {
        int n = read();
        vis.clear(); bool f = 0;
        while (n--) {
            int x = read();
            if (vis[x]) f = 1;
            vis[x] = 1;
        }
        puts(f ? "YES" : "NO");
    }
    return 0;
}