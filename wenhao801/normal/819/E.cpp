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

int cur = 0;
vector <int> out;
void add3 (int u, int v, int w) {
    ++cur;
    out.push_back(3), out.push_back(u), out.push_back(v), out.push_back(w), out.push_back(-1);
}
void add4 (int u, int v, int w, int x) {
    ++cur;
    out.push_back(4), out.push_back(u), out.push_back(v), out.push_back(w), out.push_back(x), out.push_back(-1);
}

int main () {
    int n = read(), i, j;
    if (n % 2 == 0) {
        int now;
        if (n % 4 == 0) now = 0;
        else {
            add3(6, 1, 2);
            add4(6, 2, 5, 3);
            add3(3, 4, 5);
            add3(1, 2, 3);
            add4(1, 3, 6, 4);
            add3(4, 5, 6);
            add3(2, 3, 4);
            add4(2, 4, 1, 5);
            add3(5, 6, 1);
            now = 6;
        }
        for (now; now < n; now += 4) {
            add3(now + 1, now + 2, now + 3);
            add3(now + 2, now + 3, now + 4);
            add3(now + 3, now + 4, now + 1);
            add3(now + 4, now + 1, now + 2);
            for (i = 1; i < now; i += 2)
                add4(i, now + 1, i + 1, now + 2), add4(i, now + 1, i + 1, now + 2),
                add4(i, now + 3, i + 1, now + 4), add4(i, now + 3, i + 1, now + 4);
        }
    }
    else {
        add3(1, 2, 3), add3(1, 2, 3);
        for (i = 4; i <= n; i += 2) {
            for (j = 4; j < i; j += 2)
                add4(j, i, j + 1, i + 1), add4(j, i, j + 1, i + 1);
            add4(1, i, 2, i + 1); add4(2, i, 3, i + 1);
            add3(1, i, i + 1); add3(3, i, i + 1);
        }
    }
    printf("%d\n", cur);
    for (auto i: out) if (i == -1) putchar('\n'); else printf("%d ", i);
    return 0;
}