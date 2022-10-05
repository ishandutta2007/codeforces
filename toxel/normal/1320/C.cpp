#include <bits/stdc++.h>

const int N = 1000010;
const int MAX = 1 << 20;

int a[N], ca[N], b[N], cb[N];
int x[N], y[N], z[N];
int seg[MAX << 1], lazy[MAX << 1];
std::vector <int> vec[N];
int min[N];

void pull(int sit){
    seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
}

void push(int sit){
    if (lazy[sit] == 0){
        return;
    }
    seg[sit << 1] += lazy[sit];
    lazy[sit << 1] += lazy[sit];
    seg[sit << 1 | 1] += lazy[sit];
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
    push(sit);
    int mid = (l + r) / 2;
    add(sit << 1, l, mid, ql, qr, value);
    add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

int query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return INT_MIN;
    }
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit);
    int mid = (l + r) / 2;
    return std::max(query(sit << 1, l, mid, ql, qr), query(sit << 1 | 1, mid + 1, r, ql, qr));
}

int main(){
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < MAX << 1; ++ i){
        seg[i] = INT_MIN;
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &a[i], &ca[i]);
        seg[a[i] + MAX] = std::max(seg[a[i] + MAX], -ca[i]);
    }
    for (int i = MAX - 1; i; -- i){
        pull(i);
    }
    for (int i = 0; i < N; ++ i){
        min[i] = INT_MAX;
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &b[i], &cb[i]);
        min[b[i]] = std::min(min[b[i]], cb[i]);
    }
    for (int i = 0; i < p; ++ i){
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        vec[y[i]].emplace_back(i);
    }
    int ans = INT_MIN;
    for (int i = 0; i < N - 1; ++ i){
        for (auto id : vec[i]){
            add(1, 0, MAX - 1, x[id] + 1, MAX - 1, z[id]);
        }
        if (min[i + 1] != INT_MAX){
            ans = std::max(ans, -min[i + 1] + query(1, 0, MAX - 1, 0, MAX - 1));
        }
    }
    printf("%d\n", ans);
    return 0;
}