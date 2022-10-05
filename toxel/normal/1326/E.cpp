#include <bits/stdc++.h>

const int N = 500010;
const int MAX = 1 << 19;

int p[N], q[N], inv[N];
int seg[MAX << 1], lazy[MAX << 1];

void push(int sit){
    if (lazy[sit] == 0){
        return;
    }
    seg[sit << 1] += lazy[sit];
    seg[sit << 1 | 1] += lazy[sit];
    lazy[sit << 1] += lazy[sit];
    lazy[sit << 1 | 1] += lazy[sit];
    lazy[sit] = 0;
}

void pull(int sit){
    seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return;
    }
    if (ql <= l && qr >= r){
        seg[sit] += value;
        lazy[sit] += value;
        return;
    }
    push(sit);
    int mid = (l + r) / 2;
    add(sit << 1, l, mid, ql, qr, value);
    add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

void add(int l, int r, int value){
    add(1, 0, MAX - 1, l, r, value);
}

int query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return INT_MIN;
    }
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit);
    int mid = (l + r) / 2;
    return std::max(query(sit << 1, l, mid, ql, qr), query(sit << 1 | 1, mid + 1, r, ql, qr));
}

int query(int l, int r){
    return query(1, 0, MAX - 1, l, r);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
        inv[p[i]] = i;
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &q[i]);
    }
    int cur = n;
    for (int i = 1; i <= n; ++ i){
        while (query(1, n) <= 0){
            add(1, inv[cur], 1);
            -- cur;
        }
        printf("%d%c", cur + 1, " \n"[i == n]);
        add(1, q[i], -1);
    }
    return 0;
}