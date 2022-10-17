#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define pii pair<int, int>
vector <pii> p1, p2;

int main () {
    int n = 4, i, j;
    for (i = 1; i <= n; i++) { pii a; a.first = read(), a.second = read(); p1.push_back(a); }
    for (i = 1; i <= n; i++) { pii a; a.first = read(), a.second = read(); p2.push_back(a); }
    for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) for (int k = 0; k < 4; k++) for (int l = k + 1; l < 4; l++) {
        int x1 = p1[i].first, y1 = p1[i].second;
        int x2 = p1[j].first, y2 = p1[j].second;
        int x3 = p2[k].first, y3 = p2[k].second;
        int x4 = p2[l].first, y4 = p2[l].second;
        if (x3 == x4 || y3 == y4) swap(x1, x3), swap(y1, y3), swap(x2, x4), swap(y2, y4);
        if (x1 == x2) {
            int k = (x3 - x4) == (y3 - y4) ? 1 : -1;
            int b = y3 - k * x3;
            int y = x1 * k + b;
            if (y >= min(y1, y2) && y <= max(y1, y2) && y >= min(y3, y4) && y <= max(y3, y4) && x1 >= min(x3, x4) && x1 <= max(x3, x4)) { puts("YES"); return 0; }
        }
        else {
            int k = (x3 - x4) == (y3 - y4) ? 1 : -1;
            int b = y3 - k * x3;
            int x = (y1 - b) * k;
            if (x >= min(x1, x2) && x <= max(x1, x2) && x >= min(x3, x4) && x <= max(x3, x4) && y1 >= min(y3, y4) && y1 <= max(y3, y4)) { puts("YES");  return 0; }
        }
    }
    puts("NO");
    return 0;
}