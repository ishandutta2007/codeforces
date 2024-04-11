#include <bits/stdc++.h>

const int BIT = 18;
const int MAX = 1 << BIT;
using ll = long long;

ll seg[MAX << 1];

void add(int sit, int value){
    seg[sit += MAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
    }
}

ll query(int sit, int l, int r, int ql, int qr, int offset, int dep){
    if (ql > r || qr < l){
        return 0;
    }
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    if (ql < l){
        ql = l;
    }
    if (qr > r){
        qr = r;
    }
    int mid = (l + r) / 2;
    if (offset >> dep & 1){
        int diff = 1 << dep;
        if (ql > mid){
            return query(sit << 1, l, mid, ql - diff, qr - diff, offset, dep - 1);
        }
        if (qr <= mid){
            return query(sit << 1 | 1, mid + 1, r, ql + diff, qr + diff, offset, dep - 1);
        }
        return query(sit << 1, l, mid, mid + 1 - diff, qr - diff, offset, dep - 1) +
            query(sit << 1 | 1, mid + 1, r, ql + diff, mid + diff, offset, dep - 1);
    }
    else{
        return query(sit << 1, l, mid, ql, qr, offset, dep - 1) +
            query(sit << 1 | 1, mid + 1, r, ql, qr, offset, dep - 1);
    }
}

ll query(int l, int r, int offset){
    return query(1, 0, MAX - 1, l, r, offset, BIT - 1);
}

int a[MAX << 1];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    n = 1 << n;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        add(i, a[i]);
    }
    int offset = 0;
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int x, k;
            scanf("%d%d", &x, &k);
            -- x;
            x ^= offset;
            add(x, k);
        }
        else if (type == 2){
            int k;
            scanf("%d", &k);
            offset ^= (1 << k) - 1;
        }
        else if (type == 3){
            int k;
            scanf("%d", &k);
            offset ^= 1 << k;
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            -- l, -- r;
            printf("%lld\n", query(l, r, offset));
        }
    }
    return 0;
}