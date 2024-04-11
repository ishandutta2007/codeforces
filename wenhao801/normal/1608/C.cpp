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


const int MAXN = 101000;
struct pt { int a, b, id; bool operator < (const pt &tmp) const { return a < tmp.a; } } t[MAXN];
int n;

int lo[MAXN], hi[MAXN], top; vector <int> v[MAXN];
bool ans[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) {
            t[i].a = read();
            t[i].id = i;
        }
        for (i = 1; i <= n; i++) t[i].b = read();
        sort(t + 1, t + n + 1);
        for (i = 1; i <= n; i++) {
            // printf("! %d %d\n", t[i].a, t[i].b);
            ++top; lo[top] = hi[top] = t[i].b; v[top].push_back(t[i].id);
            while (top > 1 && hi[top - 1] > lo[top]) {
                if (v[top].size() > v[top - 1].size()) swap(v[top], v[top - 1]);
                for (auto i: v[top]) v[top - 1].push_back(i);
                v[top].clear(); lo[top - 1] = min(lo[top - 1], lo[top]), hi[top - 1] = max(hi[top - 1], hi[top]);
                --top;
            }
        }
        for (auto i: v[top]) ans[i] = 1;
        for (i = 1; i <= n; i++) putchar('0' + ans[i]);
        putchar('\n');
        while (top) v[top].clear(), lo[top] = hi[top] = 0, --top;
        for (i = 1; i <= n; i++) ans[i] = 0;
    }
    return 0;
}