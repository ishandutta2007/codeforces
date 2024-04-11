#include <bits/stdc++.h>

const int N = 500010;
const int MAX = 1 << 19;
const int INF = 0x3f3f3f3f;

int next[N];
int seg[MAX << 1], lazy[MAX << 1];
std::vector <int> single[N];

void clear(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return;
    }
    seg[sit] = lazy[sit] = 0;
    if (l == r){
        return;;
    }
    int mid = (l + r) >> 1;
    clear(sit << 1, l, mid, ql, qr);
    clear(sit << 1 | 1, mid + 1, r, ql, qr);
}

void pull(int sit){
    seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
}

void push(int sit){
    if (lazy[sit]){
        seg[sit << 1] += lazy[sit];
        seg[sit << 1 | 1] += lazy[sit];
        lazy[sit << 1] += lazy[sit];
        lazy[sit << 1 | 1] += lazy[sit];
        lazy[sit] = 0;
    }
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
    int mid = (l + r) >> 1;
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

int query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return -1;
    }
    if (ql <= l && qr >= r && seg[sit] > 0){
        return -1;
    }
    if (l == r){
        return seg[sit] == 0 ? l : -1;
    }
    push(sit);
    int mid = (l + r) >> 1;
    int ret = query(sit << 1, l, mid, ql, qr);
    if (ret != -1){
        return ret;
    }
    return query(sit << 1 | 1, mid + 1, r, ql, qr);
}

int query(int ql, int qr){
    return query(1, 0, MAX - 1, ql, qr);
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &next[i]);
        single[i].clear();
    }
    clear(1, 0, MAX - 1, 1, n);
    for (int i = 1; i <= n; ++ i){
        if (next[i] != -1){
            if (next[i] <= n) {
                single[next[i]].push_back(i);
                add(i, i, 1);
            }
            add(i + 1, next[i] - 1, 1);
        }
    }
    std::vector <int> ans;
    while (ans.size() < n){
        int sit = query(1, n);
        if (sit == -1){
            puts("-1");
            return;
        }
        ans.push_back(sit);
        if (next[sit] != -1) {
            add(sit + 1, next[sit] - 1, -1);
        }
        for (auto u : single[sit]){
            add(u, u, -1);
        }
        add(sit, sit, INF);
    }
    std::reverse(ans.begin(), ans.end());
    std::vector <int> inv(n);
    for (int i = 0; i < n; ++ i){
        inv[ans[i] - 1] = i + 1;
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", inv[i], " \n"[i == n - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}