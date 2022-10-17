#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 50050;
int n, K;

struct node {
    int mn[11], mx[11], siz;
    bool operator < (const node &tmp) const {
        for (int i = 1; i <= K; i++) if (mx[i] > tmp.mn[i]) return 0;
        return 1;
    }
} now; set <node> s;

int main () {
    n = read(), K = read(); int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= K; j++) now.mn[j] = now.mx[j] = read();
        now.siz = 1;
        while (!s.empty()) {
            set <node>::iterator it = s.upper_bound(now);
            if (it == s.begin()) break;
            --it; if (!(now < *it) && !(*it < now)) {
                now.siz += (*it).siz;
                for (j = 1; j <= K; j++)
                    now.mn[j] = min(now.mn[j], (*it).mn[j]),
                    now.mx[j] = max(now.mx[j], (*it).mx[j]);
                s.erase(it);
            }
            else break;
        }
        s.insert(now);
        printf("%d\n", (*--s.end()).siz);
    }
    return 0;
}