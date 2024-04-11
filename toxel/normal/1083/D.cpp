#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
const int INF = 0x7f7f7f7f;
const int moder = (int) 1e9 + 7;

int seg[MAX << 1], seg1[MAX << 1];
//seg: min, seg1: max
int seg2[MAX << 1], seg3[MAX << 1], seg4[MAX << 1], seg5[MAX << 1];
//seg2: minmax, seg3: imax, seg4: min, seg5: max

int lazy[MAX << 1], lazy1[MAX << 1];

int a[N];
int suf[N], pre[N];

int sum(int l, int r){
    return 1ll * (l + r) * (r - l + 1) / 2 % moder;
}

void push(int sit, int l, int r){
    if (lazy[sit] == INF && lazy1[sit] == INF) return;
    int ls = sit << 1, rs = sit << 1 | 1;
    if (lazy[sit] != INF){
        seg[ls] = seg[rs] = lazy[ls] = lazy[rs] = lazy[sit];
    }
    if (lazy1[sit] != INF){
        seg1[ls] = seg1[rs] = lazy1[ls] = lazy1[rs] = lazy1[sit];
    }
    int mid = (l + r) >> 1;
    if (lazy[sit] == INF){
        seg5[ls] = seg5[rs] = 1ll * lazy1[sit] * (r - l + 1) / 2 % moder;
        seg3[ls] = 1ll * sum(l, mid) * lazy1[sit] % moder;
        seg3[rs] = 1ll * sum(mid + 1, r) * lazy1[sit] % moder;
        seg2[ls] = 1ll * lazy1[sit] * seg4[ls] % moder;
        seg2[rs] = 1ll * lazy1[sit] * seg4[rs] % moder;
    }
    else if (lazy1[sit] == INF){
        seg4[ls] = seg4[rs] = 1ll * lazy[sit] * (r - l + 1) / 2 % moder;
        seg2[ls] = 1ll * lazy[sit] * seg5[ls] % moder;
        seg2[rs] = 1ll * lazy[sit] * seg5[rs] % moder;
    }
    else{
        seg4[ls] = seg4[rs] = 1ll * lazy[sit] * (r - l + 1) / 2 % moder;
        seg5[ls] = seg5[rs] = 1ll * lazy1[sit] * (r - l + 1) / 2 % moder;
        seg3[ls] = 1ll * sum(l, mid) * lazy1[sit] % moder;
        seg3[rs] = 1ll * sum(mid + 1, r) * lazy1[sit] % moder;
        seg2[ls] = seg2[rs] = 1ll * lazy[sit] * lazy1[sit] * (r - l + 1) / 2 % moder;
    }
    lazy[sit] = lazy1[sit] = INF;
}

void pull(int sit){
    seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
    seg1[sit] = std::max(seg1[sit << 1], seg1[sit << 1 | 1]);
    seg2[sit] = (seg2[sit << 1] + seg2[sit << 1 | 1]) % moder;
    seg3[sit] = (seg3[sit << 1] + seg3[sit << 1 | 1]) % moder;
    seg4[sit] = (seg4[sit << 1] + seg4[sit << 1 | 1]) % moder;
    seg5[sit] = (seg5[sit << 1] + seg5[sit << 1 | 1]) % moder;
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        seg[sit] = lazy[sit] = value;
        seg4[sit] = 1ll * value * (r - l + 1) % moder;
        seg2[sit] = 1ll * value * seg5[sit] % moder;
        return;
    }
    push(sit, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid){
        add(sit << 1, l, mid, ql, qr, value);
    }
    if (qr > mid){
        add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    pull(sit);
}

void add1(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        seg1[sit] = lazy1[sit] = value;
        seg5[sit] = 1ll * value * (r - l + 1) % moder;
        seg3[sit] = 1ll * value * sum(l, r) % moder;
        seg2[sit] = 1ll * value * seg4[sit] % moder;
        return;
    }
    push(sit, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid){
        add1(sit << 1, l, mid, ql, qr, value);
    }
    if (qr > mid){
        add1(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    pull(sit);
}

void add(int ql, int qr, int value){
    if (ql > qr) return;
    add(1, 0, MAX - 1, ql, qr, value);
}

void add1(int ql, int qr, int value){
    if (ql > qr) return;
    add1(1, 0, MAX - 1, ql, qr, value);
}

int query(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        if (seg[sit] >= value){
            return -1;
        }
        if (l == r){
            return l;
        }
    }
    push(sit, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid){
        int ret = query(sit << 1, l, mid, ql, qr, value);
        if (ret != -1) return ret;
    }
    if (qr > mid){
        return query(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    return -1;
}

int query1(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        if (seg1[sit] <= value){
            return -1;
        }
        if (l == r){
            return l;
        }
    }
    push(sit, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid){
        int ret = query1(sit << 1, l, mid, ql, qr, value);
        if (ret != -1) return ret;
    }
    if (qr > mid){
        return query1(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    return -1;
}

int query2(int sit, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r){
        if (seg[sit] >= r){
            return -1;
        }
        if (l == r){
            return l;
        }
    }
    push(sit, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid){
        int ret = query2(sit << 1, l, mid, ql, qr);
        if (ret != -1) return ret;
    }
    if (qr > mid){
        return query2(sit << 1 | 1, mid + 1, r, ql, qr);
    }
    return -1;
}

int query3(int sit, int l, int r, int ql, int qr, int ll){
    if (ql <= l && qr >= r){
        int ret = (-seg2[sit] + 1ll * ll * seg4[sit] + seg3[sit] - 1ll * sum(l, r) * ll) % moder;
        ret += ret < 0 ? moder : 0;
        return ret;
    }
    push(sit, l, r);
    int mid = (l + r) >> 1;
    int ret = 0;
    if (ql <= mid){
        ret = query3(sit << 1, l, mid, ql, qr, ll);
    }
    if (qr > mid){
        ret += query3(sit << 1 | 1, mid + 1, r, ql, qr, ll);
    }
    ret -= ret >= moder ? moder : 0;
    return ret;
}

int query(int ql, int qr, int value){
    if (ql > qr) return -1;
    return query(1, 0, MAX - 1, ql, qr, value);
}

int query1(int ql, int qr, int value){
    if (ql > qr) return -1;
    return query1(1, 0, MAX - 1, ql, qr, value);
}

int query2(int ql, int qr){
    if (ql > qr) return -1;
    return query2(1, 0, MAX - 1, ql, qr);
}

int query3(int ql, int qr, int ll){
    if (ql > qr) return 0;
    return query3(1, 0, MAX - 1, ql, qr, ll);
}

int main(){
    memset(lazy, 0x7f, sizeof(lazy));
    memset(lazy1, 0x7f, sizeof(lazy1));
    int n;
    scanf("%d", &n);
    std::map <int, std::vector <int>> map;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        map[a[i]].push_back(i);
    }
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < n; ++ i){
        suf[i] = n;
    }
    for (auto &u : map){
        int sz = u.second.size();
        for (int i = 0; i < sz - 1; ++ i){
            suf[u.second[i]] = u.second[i + 1];
        }
        for (int i = 1; i < sz; ++ i){
            pre[u.second[i]] = u.second[i - 1];
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; -- i){
        int sit = query(i + 1, n - 1, suf[i]);
        add(i, sit == -1 ? n - 1 : sit - 1, suf[i] - 1);
        sit = query1(i + 1, n - 1, pre[i]);
        add1(i, sit == -1 ? n - 1 : sit - 1, pre[i] + 1);
        sit = query1(i, n - 1, i);
        sit = sit == -1 ? n : sit;
        int sit1 = query2(i, n - 1);
        sit1 = sit1 == -1 ? n : sit1;
        sit = std::min(sit, sit1);
        ans = (ans + query3(i, sit - 1, i)) % moder;
    }
    printf("%d\n", ans);
    return 0;
}