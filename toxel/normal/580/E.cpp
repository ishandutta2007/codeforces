#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
const int moder = 998244353;
const int mult = 37;
typedef std::pair <int, int> pii;

char s[N];
int seg[MAX << 1], lazy[MAX << 1];
int power[MAX];
int invmult;

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void init(){
    power[0] = 1;
    for (int i = 1; i < MAX; ++ i){
        power[i] = 1ll * mult * power[i - 1] % moder;
    }
    invmult = powermod(mult - 1, moder - 2);
    memset(lazy, -1, sizeof(lazy));
}

int calc(int a0, int sit, int term){
    if (power[sit] == 1) return 1ll * a0 * term % moder;
    int up = power[sit * term] - 1;
    int down = sit == 1 ? invmult : powermod(power[sit] - 1, moder - 2);
    int ret = 1ll * a0 * up % moder * down % moder;
    ret += ret < 0 ? moder : 0;
    return ret;
}

void push(int sit, int l, int r){
    if (lazy[sit] == -1) return;
    int term = r - l + 1;
    seg[sit << 1] = seg[sit << 1 | 1] = calc(lazy[sit], 1, term >> 1);
    lazy[sit << 1] = lazy[sit << 1 | 1] = lazy[sit];
    lazy[sit] = -1;
}

void pull(int sit, int l, int r){
    seg[sit] = (seg[sit << 1] + 1ll * seg[sit << 1 | 1] * power[(r - l + 1) >> 1]) % moder;
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        seg[sit] = calc(value, 1, r - l + 1);
        lazy[sit] = value;
        return;
    }
    push(sit, l, r);
    int mid = l + r >> 1;
    if (ql <= mid){
        add(sit << 1, l, mid, ql, qr, value);
    }
    if (qr > mid){
        add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    pull(sit, l, r);
}

void add(int ql, int qr, int value){
    add(1, 0, MAX - 1, ql, qr, value);
}

pii query(int sit, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r){
        return {seg[sit], r - l + 1};
    }
    push(sit, l, r);
    int mid = l + r >> 1;
    pii ret = {-1, -1};
    if (ql <= mid){
        ret = query(sit << 1, l, mid, ql, qr);
    }
    if (qr > mid){
        pii p = query(sit << 1 | 1, mid + 1, r, ql, qr);
        if (ret.first != -1){
            ret.first = (ret.first + 1ll * power[ret.second] * p.first) % moder;
            ret.second += p.second;
        }
        else{
            ret = p;
        }
    }
    return ret;
}

pii query(int ql, int qr){
    return query(1, 0, MAX - 1, ql, qr);
}

int main(){
    init();
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    m += k;
    scanf("%s", s);
    for (int i = 0; i < n; ++ i){
        add(i, i, s[i] - '0');
    }
    while (m --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int l, r, c;
            scanf("%d%d%d", &l, &r, &c);
            -- l, -- r;
            add(l, r, c);
        }
        else{
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            -- l, -- r;
            int hash1 = query(l, r).first;
            ++ r;
            int x = r - l, y = d;
            int hash2 = query(l, l + d - 1).first;
            hash2 = calc(hash2, d, x / y);
            if (x % y){
                hash2 = (hash2 + 1ll * power[x - x % y] * query(l, l + x % y - 1).first) % moder;
            }
            puts(hash1 == hash2 ? "YES" : "NO");
        }
    }
    return 0;
}