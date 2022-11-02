#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#define LL long long
#define UN unsigned short
#define ULL unsigned long long
#define pii pair <int, int>
#define piii pair <pii, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 101000;
int sum[N * 4], res[N], rn, last[N];

void updata (int rt, int l, int r, int x, int c) {
//    cout << rt << ' ' << l << ' ' << r << ' '<<x <<endl;
    if (l == r) { sum[rt] += c; return; }
    int m = (l + r) >> 1;
    if (x <= m) updata (lson, x, c);
    else updata (rson, x, c);
    sum[rt] = sum[ls] + sum[rs];
}

int query (int rt, int l, int r, int tl, int tr) {
//    cout << rt << ' ' << l <<' ' <<r << ' ' << tl << ' ' <<tr << endl;
    if (tl <= l && r <= tr) return sum[rt];
    int m = (l + r) >> 1;
    if (tr <= m) return query(lson, tl, tr);
    else if (m < tl) return query(rson, tl, tr);
    else return query (lson, tl, m) + query (rson, m + 1, tr);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, t, h, mi, s, flag = 0;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        scanf ("%d:%d:%d", &h, &mi, &s);
        int time = h * 60 * 60 + mi * 60 + s + 1;
//        cout << time << endl;
        int tmp = query (1, 1, 100000, max (1, time - t + 1), time);
//        cout << tmp << endl;
        if (tmp < m) {
            res[i] = ++rn;
            last[rn] = time;
            updata (1, 1, 100000, time, 1);
        }
        else {
            res[i] = rn;
            updata (1, 1, 100000, time, 1);
            updata (1, 1, 100000, last[rn], -1);
            last[rn] = time;
        }
        if (tmp + 1 >= m) flag = 1;
    }
    if (!flag) cout << "No solution\n";
    else {
        cout << rn << endl;
        for (int i = 1; i <= n; i++) {
            printf ("%d\n", res[i]);
        }
    }
}