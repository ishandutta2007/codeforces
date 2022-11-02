#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, LL>

using namespace std;

const int N = 100005, mod = 1e9 + 7, M = 100;
int n, m, k;
int q[N][6], a[N][6], r[6], f[6], e[6];

inline void inq (int id, int x) {
    while (f[id] <= e[id] && a[x][id] >= a[q[e[id]][id]][id]) e[id]--;
    q[++e[id]][id] = x;
}

inline void outq (int id, int x) {
    if (q[f[id]][id] <= x) f[id]++;
}

inline int jug () {
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += a[q[f[i]][i]][i];
    }
    return sum > k;
}

inline int read() {
    int x=0; char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = read ();
        }
    }
    for (int i = 1; i <= m; i++) f[i] = 0, e[i] = -1;
    int res = 0;
    int pre = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            inq (j, i);
        }
        while (pre <= i && jug ()) {
            for (int j = 1; j <= m; j++) outq(j, pre);
            pre++;
        }
        if (res < i - pre + 1) {
            res = i - pre + 1;
            for (int j = 1; j <= m; j++) r[j] = a[q[f[j]][j]][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << r[i] << ' ';
    }
}