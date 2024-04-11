#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;

const int MAX = 1 << 18;

ll seg[MAX << 1];
ll lazy[MAX << 1];

void push(int sit, int l, int r){
    if (~lazy[sit]){
        seg[sit << 1] = seg[sit << 1 | 1] = lazy[sit] * (r - l + 1 >> 1);
        lazy[sit << 1] = lazy[sit << 1 | 1] = lazy[sit];
        lazy[sit] = -1;
    }
}

void pull(int sit){
    seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
}

void add(int sit, int ql, int qr, int l, int r, int value){
    if (ql <= l && qr >= r){
        seg[sit] = 1ll * value * (r - l + 1);
        lazy[sit] = value;
        return;
    }
    push(sit, l, r);
    int mid = l + r >> 1;
    if (ql <= mid){
        add(sit << 1, ql, qr, l, mid, value);
    }
    if (qr > mid){
        add(sit << 1 | 1, ql, qr, mid + 1, r, value);
    }
    pull(sit);
}

void add(int ql, int qr, int value){
    if (ql > qr) return;
    add(1, ql, qr, 0, MAX - 1, value);
}

ll query(int sit, int ql, int qr, int l, int r){
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit, l, r);
    int mid = l + r >> 1;
    ll ret = 0;
    if (ql <= mid){
        ret += query(sit << 1, ql, qr, l, mid);
    }
    if (qr > mid){
        ret += query(sit << 1 | 1, ql, qr, mid + 1, r);
    }
    return ret;
}

ll query(int ql, int qr){
    return query(1, ql, qr, 0, MAX - 1);
}

struct Pair{
    int value;
    int sit;

    Pair():value(0), sit(0){}
    Pair(int value, int sit):value(value), sit(sit){}

    bool operator < (const Pair &p)const{
        if (value != p.value){
            return value > p.value;
        }
        return sit < p.sit;
    }
};

std::vector <int> fact[N];
int a[N], cnt[N];
std::vector <int> vec[N];

void modify(std::set <Pair> &set, int value, int sit){
    Pair p(value, sit);
    auto u = set.upper_bound(p);
    if (u -> sit > sit) return;
    add(u -> sit, sit, value);
    int tmpsit = u -> sit;
    while (u -> sit <= sit){
        auto v = ++ u;
        -- u;
        if (v -> sit > sit + 1){
            set.insert(Pair(u -> value, sit + 1));
        }
        set.erase(u);
        u = v;
    }
    set.insert(Pair(value, tmpsit));
}

int main(){
    memset(lazy, -1, sizeof(lazy));
    for (int i = 1; i < N; ++ i){
        for (int j = i; j < N; j += i){
            fact[j].push_back(i);
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        for (auto u : fact[a[i]]){
            vec[u].push_back(i);
        }
    }
    std::set <Pair> set;
    set.insert(Pair(0, 0));
    set.insert(Pair(0, n + 1));
    for (int i = 1; i < N; ++ i){
        if (vec[i].size() < 2) continue;
        std::reverse(vec[i].begin(), vec[i].end());
        modify(set, i, vec[i][1]);
    }
    ll ans = query(1, n);
    for (int i = 0; i < n - 1; ++ i){
        for (auto u : fact[a[i]]){
            if (vec[u].size() < 2 || cnt[u] >= 2) continue;
            if (!cnt[u]){
                modify(set, u, vec[u][0]);
            }
            else if (cnt[u] == 1){
                modify(set, u, n);
            }
            ++ cnt[u];
        }
        ans += query(i + 2, n);
    }
    printf("%lld\n", ans);
}