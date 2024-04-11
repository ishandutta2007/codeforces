#include <bits/stdc++.h>

const int MAX = 1 << 19;

struct Seg{
    int seg[MAX << 1];

    int query(int sit, int ql, int qr, int l, int r, int value){
        if (ql > r || qr < l){
            return -1;
        }
        if (seg[sit] < value){
            return -1;
        }
        if (l == r){
            return sit - MAX;
        }
        int mid = (l + r) >> 1;
        int ret = query(sit << 1, ql, qr, l, mid, value);
        if (ret != -1){
            return ret;
        }
        return query(sit << 1 | 1, ql, qr, mid + 1, r, value);
    }

    int query(int ql, int qr, int value){
        return query(1, ql, qr, 0, MAX - 1, value);
    }
};

const int N = 300010;

int a[N], left[N];
Seg seg1, seg2;

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = n + 1; i <= 3 * n; ++ i){
        a[i] = a[i - n];
    }
    for (int i = 1; i <= 3 * n; ++ i){
        seg1.seg[i + MAX] = a[3 * n + 1 - i];
    }
    for (int i = MAX - 1; i; -- i){
        seg1.seg[i] = std::max(seg1.seg[i << 1], seg1.seg[i << 1 | 1]);
    }
    for (int i = 2; i <= 3 * n; ++ i){
        left[i] = seg1.query(3 * n + 1 - (i - 1), 3 * n, 2 * a[i] + 1);
        if (left[i] != -1){
            left[i] = 3 * n + 1 - left[i];
        }
        seg2.seg[i + MAX] = left[i];
    }
    left[1] = -1;
    for (int i = MAX - 1; i; -- i){
        seg2.seg[i] = std::max(seg2.seg[i << 1], seg2.seg[i << 1 | 1]);
    }
    for (int i = 1; i <= n; ++ i){
        int ans = seg2.query(i, 3 * n, i);
        if (ans != -1){
            ans -= i;
        }
        printf("%d%c", ans, " \n"[i == n]);
    }
    return 0;
}