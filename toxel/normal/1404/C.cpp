#include <bits/stdc++.h>

const int N = 300010;
const int MAX = 1 << 19;
const int INF = 1e9;

int seg[MAX << 1], lazy[MAX << 1];

void pull(int sit){
    seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
}

void push(int sit){
    if (!lazy[sit]){
        return;
    }
    seg[sit << 1] += lazy[sit];
    seg[sit << 1 | 1] += lazy[sit];
    lazy[sit << 1] += lazy[sit];
    lazy[sit << 1 | 1] += lazy[sit];
    lazy[sit] = 0;
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return;
    }
    if (ql <= l && qr >= r){
        seg[sit] += value;
        lazy[sit] += value;
        return;
    }
    int mid = (l + r) / 2;
    push(sit);
    add(sit << 1, l, mid, ql, qr, value);
    add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

void add(int ql, int qr, int value){
    if (ql > qr){
        return;
    }
    add(1, 0, MAX - 1, ql, qr, value);
}

int query1(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return INT_MAX;
    }
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    int mid = (l + r) / 2;
    push(sit);
    return std::min(query1(sit << 1, l, mid, ql, qr), query1(sit << 1 | 1, mid + 1, r, ql, qr));
}

int query1(int ql, int qr){
    if (ql > qr){
        return INT_MAX;
    }
    return query1(1, 0, MAX - 1, ql, qr);
}

int query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return -1;
    }
    if (seg[sit] > 0){
        return -1;
    }
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    push(sit);
    int ret = query(sit << 1, l, mid, ql, qr);
    if (ret != -1){
        return ret;
    }
    return query(sit << 1 | 1, mid + 1, r, ql, qr);
}

int query(int l, int r){
    if (l > r){
        return -1;
    }
    return query(1, 0, MAX - 1, l, r);
}

using pii = std::pair <int, int>;

std::vector<pii> event[N];
int c[N];

void add(int sit, int value){
    for ( ; sit < N; sit += sit & -sit){
        c[sit] += value;
    }
}

int query(int sit){
    int ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

int ans[N];
int a[N];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        event[x + 1].emplace_back(n - y, i);
    }
    for (int i = n; i >= 1; -- i){
        if (i < a[i]){
            add(i, i, INF);
        }
        else if (i > a[i]){
            add(i, i, i - a[i]);
        }
        else{
            int cur = i;
            while (cur != -1){
                add(cur + 1, n, -1);
                add(cur, cur, INF);
                add(cur, 1);
                cur = query(cur + 1, n);
            }
        }
        for (auto u : event[i]){
            ans[u.second] = query(u.first);
        }
    }
    for (int i = 0; i < q; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}