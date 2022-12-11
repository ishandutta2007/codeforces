#include <bits/stdc++.h>

const int N = 1000010;
const int MAX = 1 << 20;

int seg[MAX << 1], lazy[MAX << 1];

void pull(int sit){
    seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
}

void push(int sit){
    if (!lazy[sit]){
        return;
    }
    seg[sit << 1] += lazy[sit], seg[sit << 1 | 1] += lazy[sit];
    lazy[sit << 1] += lazy[sit], lazy[sit << 1 | 1] += lazy[sit];
    lazy[sit] = 0;
}

void add(int sit, int l, int r, int ql, int qr, int value) {
    if (l > qr || r < ql) {
        return;
    }
    if (ql <= l && qr >= r) {
        seg[sit] += value;
        lazy[sit] += value;
        return;
    }
    push(sit);
    int mid = (l + r) >> 1;
    add(sit << 1, l, mid, ql, qr, value);
    add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

void add(int ql, int qr, int value){
    add(1, 0, MAX - 1, ql, qr, value);
}

int query(int sit, int l, int r, int ql, int qr){
    if (l > qr || r < ql){
        return -1;
    }
    if (l == r){
        return seg[sit] >= 0 ? -1 : l;
    }
    if (ql <= l && qr >= r && seg[sit] >= 0){
        return -1;
    }
    push(sit);
    int mid = (l + r) >> 1;
    int ret = query(sit << 1 | 1, mid + 1, r, ql, qr);
    if (ret != -1){
        return ret;
    }
    return query(sit << 1, l, mid, ql, qr);
}

int a[MAX], b[MAX];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        a[i] = x;
        add(0, x, -1);
    }
    for (int i = 0, x; i < m; ++ i){
        scanf("%d", &x);
        b[i] = x;
        add(0, x, 1);
    }
    int q;
    scanf("%d", &q);
    while (q --){
        int type, sit, x;
        scanf("%d%d%d", &type, &sit, &x);
        -- sit;
        if (type == 1){
            add(0, a[sit], 1);
            a[sit] = x;
            add(0, a[sit], -1);
        }
        else{
            add(0, b[sit], -1);
            b[sit] = x;
            add(0, b[sit], 1);
        }
        printf("%d\n", query(1, 0, MAX - 1, 0, MAX - 1));
    }
    return 0;
}