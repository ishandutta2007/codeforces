#include <bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
using ll = long long;

struct Seg{
    ll sum;
    int min, max, lazy{-1};

    void pull(Seg s1, Seg s2){
        sum = s1.sum + s2.sum;
        min = std::min(s1.min, s2.min);
        max = std::max(s1.max, s2.max);
    }
};

Seg seg[MAX << 1];
int a[N];

void pull(int sit){
    seg[sit].pull(seg[sit << 1], seg[sit << 1 | 1]);
}

void update(Seg &s, int l, int r, int value){
    s.sum = 1ll * (r - l + 1) * value;
    s.min = s.max = s.lazy = value;
}

void push(int sit, int l, int r){
    int &u = seg[sit].lazy;
    if (u == -1){
        return;
    }
    int mid = (l + r) / 2;
    update(seg[sit << 1], l, mid, u);
    update(seg[sit << 1 | 1], mid + 1, r, u);
    u = -1;
}

void add1(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return;
    }
    if (ql <= l && qr >= r){
        update(seg[sit], l, r, value);
        return;
    }
    push(sit, l, r);
    int mid = (l + r) / 2;
    add1(sit << 1, l, mid, ql, qr, value);
    add1(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

void add1(int l, int r, int value){
    add1(1, 0, MAX - 1, l, r, value);
}

void add2(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l || seg[sit].max < value){
        return;
    }
    if (ql <= l && qr >= r && seg[sit].min == seg[sit].max){
        update(seg[sit], l, r, seg[sit].min % value);
        return;
    }
    push(sit, l, r);
    int mid = (l + r) / 2;
    add2(sit << 1, l, mid, ql, qr, value);
    add2(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

void add2(int l, int r, int value){
    add2(1, 0, MAX - 1, l, r, value);
}

ll query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return 0;
    }
    if (ql <= l && qr >= r){
        return seg[sit].sum;
    }
    push(sit, l, r);
    int mid = (l + r) / 2;
    return query(sit << 1, l, mid, ql, qr) + query(sit << 1 | 1, mid + 1, r, ql, qr);
}

ll query(int l, int r){
    return query(1, 0, MAX - 1, l, r);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        update(seg[i + MAX], i, i, a[i]);
    }
    for (int i = MAX - 1; i; -- i){
        pull(i);
    }
    while (m --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int l, r;
            scanf("%d%d", &l, &r);
            -- l, -- r;
            printf("%lld\n", query(l, r));
        }
        else if (type == 2){
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            -- l, -- r;
            add2(l, r, x);
        }
        else if (type == 3){
            int k, x;
            scanf("%d%d", &k, &x);
            -- k;
            add1(k, k, x);
        }
    }
    return 0;
}