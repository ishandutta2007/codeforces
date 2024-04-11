#include <bits/stdc++.h>

const int MAX = 1 << 18;
const int N = 200010;

int seg[MAX << 1], lazy[MAX << 1];

void update(int sit, int value){
    seg[sit] = std::max(seg[sit], value);
    lazy[sit] = std::max(lazy[sit], value);
}
void push(int sit){
    if (lazy[sit] == -1){
        return;
    }
    update(sit << 1, lazy[sit]);
    update(sit << 1 | 1, lazy[sit]);
    lazy[sit] = -1;
}

void pull(int sit){
    seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return;
    }
    if (ql <= l && qr >= r){
        update(sit, value);
        return;
    }
    push(sit);
    int mid = (l + r) >> 1;
    add(sit << 1, l, mid, ql, qr, value);
    add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

void push(int sit, int l, int r, int q){
    if (q > r || q < l){
        return;
    }
    if (q <= l && q >= r){
        return;
    }
    push(sit);
    int mid = (l + r) >> 1;
    push(sit << 1, l, mid, q);
    push(sit << 1 | 1, mid + 1, r, q);
    pull(sit);
}

int main(){
    memset(lazy, -1, sizeof(lazy));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &seg[i + MAX]);
    }
    for (int i = MAX - 1; i; -- i){
        seg[i] = std::max(seg[i << 1], seg[i << 1 | 1]);
    }
    int q;
    scanf("%d", &q);
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int p, x;
            scanf("%d%d", &p, &x);
            -- p;
            push(1, 0, MAX - 1, p);
            seg[p += MAX] = x;
            for (p >>= 1; p; p >>= 1){
                seg[p] = std::max(seg[p << 1], seg[p << 1 | 1]);
            }
        }
        else{
            int x;
            scanf("%d", &x);
            add(1, 0, MAX - 1, 0, n - 1, x);
        }
    }
    for (int i = 0; i < n; ++ i){
        push(1, 0, MAX - 1, i);
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", seg[i + MAX], " \n"[i == n - 1]);
    }
    return 0;
}