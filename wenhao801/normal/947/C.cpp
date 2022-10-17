#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 300300;
int ch[MAXN * 33][2], a[MAXN], b[MAXN], n, siz[MAXN * 33], top = 1;
void add (int x, int k) {
    int now = 1; siz[1] += k;
    for (int i = 29; i >= 0; i--) {
        int to = (x >> i) & 1;
        if (!ch[now][to]) ch[now][to] = ++top;
        now = ch[now][to]; siz[now] += k;
    }
}
int get (int x) {
    int now = 1, res = 0;
    for (int i = 29; i >= 0; i--) {
        int to = ((x >> i) & 1);
        if (siz[ch[now][to]]) now = ch[now][to], res += to << i;
        else now = ch[now][to ^ 1], res += (to ^ 1) << i;
    }
    return res;
}

int main () {
    n = read(); int i,j ;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= n; i++) b[i] = read(), add(b[i],1 );
    for (i = 1; i <= n; i++) {
        int tmp = get(a[i]); printf("%d ", tmp ^ a[i]);
        add(tmp, -1);
    }
    return 0;
}