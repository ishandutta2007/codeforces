#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 200010;
const int MAX = 1 << 18;

int p[N];

void sub(int &a, int b){a -= b, a += a < 0 ? moder : 0;}
void add(int &a, int b){a += b, a -= a >= moder ? moder : 0;}

struct Seg{
    int k1, k2, b;

    Seg():k1(1), k2(0), b(0){}

    Seg merge(const Seg &s)const{
        Seg ret;
        ret.k1 = 1ll * k1 * s.k1 % moder;
        ret.k2 = (1ll * k1 * s.k2 + k2) % moder;
        ret.b = (1ll * k1 * s.b + b) % moder;
        return ret;
    }
};

Seg seg[MAX << 1];

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

int query(int l, int r){
    Seg retl, retr;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) retl = retl.merge(seg[l ++]);
        if (r & 1) retr = seg[-- r].merge(retr);
    }
    retl = retl.merge(retr);
    int ret = 1ll * powermod(1 - retl.k2, moder - 2) * retl.b % moder;
    ret += ret < 0 ? moder : 0;
    return ret;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &p[i]);
        seg[i + MAX].k1 = 1ll * powermod(100, moder - 2) * p[i] % moder;
        seg[i + MAX].k2 = 1 - seg[i + MAX].k1;
        seg[i + MAX].k2 += seg[i + MAX].k2 < 0 ? moder : 0;
        seg[i + MAX].b = 1;
    }
    for (int i = MAX - 1; i; -- i){
        seg[i] = seg[i << 1].merge(seg[i << 1 | 1]);
    }
    std::set <int> set;
    set.insert(0);
    set.insert(n);
    int sum = query(0, n - 1);
    while (q --){
        int pos;
        scanf("%d", &pos);
        -- pos;
        if (set.count(pos)){
            auto u = set.find(pos);
            -- u;
            int prev = *u;
            sub(sum, query(prev, pos - 1));
            ++ u, ++ u;
            int suf = *u;
            sub(sum, query(pos, suf - 1));
            set.erase(pos);
            add(sum, query(prev, suf - 1));
        }
        else{
            auto u = set.lower_bound(pos);
            int suf = *u;
            -- u;
            int prev = *u;
            sub(sum, query(prev, suf - 1));
            add(sum, query(pos, suf - 1));
            add(sum, query(prev, pos - 1));
            set.insert(pos);
        }
        printf("%d\n", sum);
    }
}