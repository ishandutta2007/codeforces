#include<bits/stdc++.h>

const int N = 400010;
const int MAX = 1 << 19;
const int M = 310; 
const int moder = (int) 1e9 + 7;

int min[M], inv[M];
std::vector <int> prime;
std::bitset <MAX << 1> seg[M], lazy[M];
int seg1[MAX << 1], lazy1[MAX << 1];
int a[N];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1) ret = 1ll * ret * a % moder;
        a = 1ll * a * a % moder;
    }
    return ret;
}

void push(int id, int sit){
    if (!lazy[id][sit]) return;
    lazy[id][sit << 1] = lazy[id][sit << 1 | 1] = 
    seg[id][sit << 1] = seg[id][sit << 1 | 1] = true;
    lazy[id][sit] = false;
}

void push1(int sit, int l, int r){
    if (lazy1[sit] == 1) return;
    lazy1[sit << 1] = 1ll * lazy1[sit] * lazy1[sit << 1] % moder;
    lazy1[sit << 1 | 1] = 1ll * lazy1[sit] * lazy1[sit << 1 | 1] % moder;
    seg1[sit << 1] = 1ll * powermod(lazy1[sit], (r - l + 1) / 2) * seg1[sit << 1] % moder;
    seg1[sit << 1 | 1] = 1ll * powermod(lazy1[sit], (r - l + 1) / 2) * seg1[sit << 1 | 1] % moder;
    lazy1[sit] = 1;
}

void pull(int id, int sit){
    seg[id][sit] = seg[id][sit << 1] || seg[id][sit << 1 | 1];
}

void pull1(int sit){
    seg1[sit] = 1ll * seg1[sit << 1] * seg1[sit << 1 | 1] % moder;
}

void add(int id, int sit, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r){
        seg[id][sit] = lazy[id][sit] = true;
        return;
    }
    push(id, sit);
    int mid = (l + r) >> 1;
    if (ql <= mid){
        add(id, sit << 1, l, mid, ql, qr);
    }
    if (qr > mid){
        add(id, sit << 1 | 1, mid + 1, r, ql, qr);
    }
    pull(id, sit);
}

void add1(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        seg1[sit] = 1ll * seg1[sit] * powermod(value, r - l + 1) % moder;
        lazy1[sit] = 1ll * lazy1[sit] * value % moder;
        return;
    }
    push1(sit, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid){
        add1(sit << 1, l, mid, ql, qr, value);
    }
    if (qr > mid){
        add1(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    pull1(sit);
}

bool query(int id, int sit, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r){
        return seg[id][sit];
    }
    push(id, sit);
    int mid = (l + r) >> 1;
    bool ret = false;
    if (ql <= mid){
        ret = ret || query(id, sit << 1, l, mid, ql, qr);
    }
    if (qr > mid){
        ret = ret || query(id, sit << 1 | 1, mid + 1, r, ql, qr);
    }
    return ret;
}

int query1(int sit, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r){
        return seg1[sit];
    }
    push1(sit, l, r);
    int mid = (l + r) >> 1;
    int ret = 1;
    if (ql <= mid){
        ret = 1ll * ret * query1(sit << 1, l, mid, ql, qr) % moder;
    }
    if (qr > mid){
        ret = 1ll * ret * query1(sit << 1 | 1, mid + 1, r, ql, qr) % moder;
    }
    return ret;
}

int main(){
    inv[1] = 1;
    for (int i = 2; i < M; ++ i){
        inv[i] = moder - 1ll * (moder / i) * inv[moder % i] % moder;
    }
    for (int i = 0; i < MAX << 1; ++ i){
        seg1[i] = lazy1[i] = 1;
    }
    for (int i = 2; i < M; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (i * u >= M) break;
            min[i * u] = u;
            if (i % u == 0) break;
        }
    }
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        add1(1, 0, MAX - 1, i, i, a[i]);
        while (a[i] > 1){
            add(min[a[i]], 1, 0, MAX - 1, i, i);
            a[i] /= min[a[i]];
        }
    }
    while (q --){
        char s[100];
        scanf("%s", s);
        if (s[0] == 'M'){
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            -- l, -- r;
            add1(1, 0, MAX - 1, l, r, x);
            while (x > 1){
                add(min[x], 1, 0, MAX - 1, l, r);
                x /= min[x];
            }
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            -- l, -- r;
            int prod = query1(1, 0, MAX - 1, l, r);
            for (auto u : prime){
                if (query(u, 1, 0, MAX - 1, l, r)){
                    prod = 1ll * prod * inv[u] % moder * (u - 1) % moder;
                }
            }
            printf("%d\n", prod);
        }
    }
    return 0;
}