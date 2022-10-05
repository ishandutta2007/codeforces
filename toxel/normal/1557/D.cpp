#include <bits/stdc++.h>

const int MAX = 1 << 20;
const int N = 1000010;
using pii = std::pair <int, int>;

int pre[N];
int dp[N];
int c[N];
std::vector <pii> vec[N];
pii seg[MAX << 1], lazy[MAX << 1];
bool vis[N];

void push(int sit){
    seg[sit << 1] = std::max(seg[sit << 1], lazy[sit]);
    seg[sit << 1 | 1] = std::max(seg[sit << 1 | 1], lazy[sit]);
    lazy[sit << 1] = std::max(lazy[sit << 1], lazy[sit]);
    lazy[sit << 1 | 1] = std::max(lazy[sit << 1 | 1], lazy[sit]);
    lazy[sit] = {0, 0};
}

void pull(int sit){
    seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
}

void add(int sit, int l, int r, int ql, int qr, pii val){
    if (ql > r || qr < l){
        return;
    }
    if (ql <= l && r <= qr){
        seg[sit] = std::max(seg[sit], val);
        lazy[sit] = std::max(lazy[sit], val);
        return;
    }
    push(sit);
    int mid = (l + r) / 2;
    add(sit << 1, l, mid, ql, qr, val);
    add(sit << 1 | 1, mid + 1, r, ql, qr, val);
    pull(sit);
}

pii query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return {INT_MIN, INT_MIN};
    }
    if (ql <= l && r <= qr){
        return seg[sit];
    }
    push(sit);
    int mid = (l + r) / 2;
    return std::max(query(sit << 1, l, mid, ql, qr), query(sit << 1 | 1, mid + 1, r, ql, qr));
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < m; ++ i){
        int id, l, r;
        scanf("%d%d%d", &id, &l, &r);
        vec[id].emplace_back(l, r);
        c[cnt ++] = l;
        c[cnt ++] = r + 1;
    }
    std::sort(c, c + cnt);
    cnt = std::unique(c, c + cnt) - c;
    for (int i = 1; i <= n; ++ i){
        for (auto p : vec[i]){
            int l = std::lower_bound(c, c + cnt, p.first) - c;
            int r = std::lower_bound(c, c + cnt, p.second + 1) - c;
            pii pair = query(1, 0, MAX - 1, l, r - 1);
            if (dp[i] < pair.first + 1){
                dp[i] = pair.first + 1;
                pre[i] = pair.second;
            }
        }
        for (auto p : vec[i]){
            int l = std::lower_bound(c, c + cnt, p.first) - c;
            int r = std::lower_bound(c, c + cnt, p.second + 1) - c;
            add(1, 0, MAX - 1, l, r - 1, {dp[i], i});
        }
    }
    int pos = std::max_element(dp + 1, dp + n + 1) - dp;
    std::vector <int> ans;
    while (pos > 0){
        vis[pos] = true;
        pos = pre[pos];
    }
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            ans.emplace_back(i);
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
    return 0;
}