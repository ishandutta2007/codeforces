#include <bits/stdc++.h>

const int N = 200010;
const int MAX = 1 << 18;

int a[N];
int seg[MAX << 1], lazy[MAX << 1];

void modify(int sit, int value){
    seg[sit] += value;
    lazy[sit] += value;
}

void push(int sit){
    if (!lazy[sit]){
        return;
    }
    modify(sit << 1, lazy[sit]);
    modify(sit << 1 | 1, lazy[sit]);
    lazy[sit] = 0;
}

void pull(int sit){
    seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return;
    }
    if (ql <= l && qr >= r){
        modify(sit, value);
        return;
    }
    push(sit);
    int mid = (l + r) / 2;
    add(sit << 1, l, mid, ql, qr, value);
    add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

void add(int pos, int value){
    add(1, 0, MAX - 1, 0, pos, value);
}

int query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return -1;
    }
    if (l == r){
        return seg[sit] < 0 ? l : -1;
    }
    if (ql <= l && qr >= r && seg[sit] >= 0){
        return -1;
    }
    push(sit);
    int mid = (l + r) / 2;
    int ret = query(sit << 1 | 1, mid + 1, r, ql, qr);
    if (ret != -1){
        return ret;
    }
    return query(sit << 1, l, mid, ql, qr);
}

int main(){
    int m;
    scanf("%d", &m);
    for (int i = 0; i <= m; ++ i){
        add(i, -1);
        a[i] = -1;
    }
    for (int i = 1; i <= m; ++ i){
        int p, type;
        scanf("%d%d", &p, &type);
        if (type == 0){
            add(p + m, 1);
        }
        else{
            int x;
            scanf("%d", &x);
            add(p + m, -1);
            a[p + m] = x;
        }
        int sit = query(1, 0, MAX - 1, 0, MAX - 1);
        assert(sit >= 0);
        printf("%d\n", a[sit]);
    }
    return 0;
}