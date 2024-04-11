#include <bits/stdc++.h>
#define ls(u) ((u) << 1)
#define rs(u) ((u) << 1 | 1)

using ll = long long;
using pii = std::pair <ll, ll>;

pii merge(pii p1, pii p2){
    if (p1.first != p2.first){
        return std::min(p1, p2);
    }
    return {p1.first, p1.second + p2.second};
}

const int N = 1 << 19;
int MAX;

struct Seg{
    pii seg[N << 1];
    ll lazy[N << 1];

    void init(){
        memset(seg, 0, sizeof(seg[0]) * 2 * MAX);
        memset(lazy, 0, sizeof(lazy[0]) * 2 * MAX);
    }

    void putone(){
        for (int i = MAX; i < MAX + MAX; ++ i){
            seg[i] = {0, 1};
        }
        for (int i = MAX - 1; i; -- i){
            pull(i);
        }
    }

    void pull(int sit){
        seg[sit] = merge(seg[ls(sit)], seg[rs(sit)]);
    }

    void push(int sit){
        if (!lazy[sit]){
            return;
        }
        lazy[ls(sit)] += lazy[sit];
        lazy[rs(sit)] += lazy[sit];
        seg[ls(sit)].first += lazy[sit];
        seg[rs(sit)].first += lazy[sit];
        lazy[sit] = 0;
    }

    int query(int sit, int l, int r, int ql, int qr, ll value){
        if (ql > r || qr < l){
            return -1;
        }
        if (seg[sit].first >= value){
            return -1;
        }
        if (l == r){
            return l;
        }
        push(sit);
        int mid = (l + r) / 2;
        int ret = query(ls(sit), l, mid, ql, qr, value);
        if (ret != -1){
            return ret;
        }
        return query(rs(sit), mid + 1, r, ql, qr, value);
    }

    pii query1(int sit, int l, int r, int ql, int qr){
        if (ql > r || qr < l){
            return {LLONG_MAX, 0};
        }
        if (ql <= l && qr >= r){
            return seg[sit];
        }
        push(sit);
        int mid = (l + r) / 2;
        return merge(query1(ls(sit), l, mid, ql, qr),
                     query1(rs(sit), mid + 1, r, ql, qr));
    }

    void add(int sit, int l, int r, int ql, int qr, ll value){
        if (ql > r || qr < l){
            return;
        }
        if (ql <= l && qr >= r){
            seg[sit].first += value;
            lazy[sit] += value;
            return;
        }
        push(sit);
        int mid = (l + r) / 2;
        add(ls(sit), l, mid, ql, qr, value);
        add(rs(sit), mid + 1, r, ql, qr, value);
        pull(sit);
    }

    void add(int l, int r, int value){
        if (l > r) return;
        add(1, 0, MAX - 1, l, r, value);
    }

    pii query(int l, int r){
        if (l > r) return {LLONG_MAX, 0};
        return query1(1, 0, MAX - 1, l, r);
    }
};

Seg seg1, seg2;
int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    MAX = 8;
    while (MAX < 5 * n){
        MAX *= 2;
    }
    MAX = std::min(MAX, N);
    seg1.putone();
    seg2.putone();
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    int numodd = (n + 1) / 2, numeven = n / 2;
    ll ans = 0;
    for (int i = n; i >= 1; -- i){
        int leftodd, lefteven;
        if (i % 2 == 1){
            leftodd = (i + 1) / 2;
            lefteven = (i + 1) / 2;
        }
        else{
            leftodd = i / 2 + 1;
            lefteven = i / 2;
        }
        seg1.add(leftodd, numodd, i % 2 == 1 ? a[i] : -a[i]);
        seg2.add(lefteven, numeven, i % 2 == 0 ? a[i] : -a[i]);
        int oddfi = seg1.query(1, 0, MAX - 1, leftodd, numodd, 0);
        int evenfi = seg2.query(1, 0, MAX - 1, lefteven, numeven, 0);
        int fi = n + 1;
        if (oddfi != -1){
            fi = std::min(fi, 2 * oddfi - 1);
        }
        if (evenfi != -1){
            fi = std::min(fi, 2 * evenfi);
        }
        fi -= 1;
        int fiodd = fi % 2 == 0 ? fi - 1 : fi;
        pii p1 = seg1.query(leftodd, (fiodd + 1) / 2);
        int fieven = fi % 2 == 1 ? fi - 1 : fi;
        pii p2 = seg2.query(lefteven, fieven / 2);
        p1 = merge(p1, p2);
        if (p1.first == 0){
            ans += p1.second;
        }
    }
    printf("%lld\n", ans);
    seg1.init();
    seg2.init();
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}