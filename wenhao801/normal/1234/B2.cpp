#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <deque>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

map <int, bool> vis;

deque <int> q;

int main () {
    int n = read(), k = read();
    int i, j;
    for (i = 1; i <= n; i++) {
        int x = read();
        if (vis[x]) continue;
        vis[x] = true;
        q.push_front(x);
        if (q.size() > k) { vis[q.back()] = false; q.pop_back(); }
    }
    printf("%d\n", q.size());
    while (!q.empty()) {
        printf("%d ", q.front());
        q.pop_front();
    }
    return 0;
}