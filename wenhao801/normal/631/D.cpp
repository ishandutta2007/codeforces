#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long
const int MAXN = 200200;

struct block {
    int num; char c;
    block (int x = 0, char y = '.') { num = x, c = y; }
    bool operator == (const block &x) const { return (num == x.num) && (c == x.c); }
    bool operator != (const block &x) const { return (num != x.num) || (c != x.c); }
} s[MAXN], t[MAXN], tmp[MAXN];
inline block read () {
    int p = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') p = p * 10 + c - '0', c = getchar();
    c = getchar(); return block(p, c);
}

int n, m, top;
int nex[MAXN];

signed main () {
    scanf("%lld%lld", &n, &m);
    int i, j;
    for (i = 1; i <= n; i++) {
        s[i] = read();
        if (i != 1 && s[i].c == s[i - 1].c) {
            --n; --i;
            s[i].num += s[i + 1].num;
        }
    }
    for (i = 1; i <= m; i++) {
        t[i] = read();
        if (i != 1 && t[i].c == t[i - 1].c) {
            --m; --i;
            t[i].num += t[i + 1].num;
        }
    }
    int ans = 0;
    if (m == 1) {
        for (i = 1; i <= n; i++) 
            if (s[i].c == t[1].c && s[i].num >= t[1].num) ans += s[i].num - t[1].num + 1;
    }
    else {
        for (i = 2; i < m; i++) tmp[++top] = t[i];
        nex[1] = 0;
        for (i = 2, j = 0; i <= top; i++) {
            while (j && tmp[i] != tmp[j + 1]) j = nex[j];
            if (tmp[i] == tmp[j + 1]) ++j;
            nex[i] = j;
        }
        for (i = 1, j = 0; i <= n; i++) {
            while (j && s[i] != tmp[j + 1]) j = nex[j];
            if (s[i] == tmp[j + 1]) ++j;
            if (j == top) {
                if (s[i + 1].num >= t[m].num && s[i - top].num >= t[1].num && s[i + 1].c == t[m].c && s[i - top].c == t[1].c)
                    ++ans;
                j = nex[j];
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}