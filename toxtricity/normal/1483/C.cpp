#include <bits/stdc++.h>

const int N = 300010;
const int MAX = 1 << 19;
using ll = long long;

ll seg[MAX << 1], lazy[MAX << 1];

void push(int sit){
    if (lazy[sit] == 0){
        return;
    }
    seg[sit << 1] += lazy[sit];
    seg[sit << 1 | 1] += lazy[sit];
    lazy[sit << 1] += lazy[sit];
    lazy[sit << 1 | 1] += lazy[sit];
    lazy[sit] = 0;
}

void pull(int sit){
    seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
}

void add(int sit, int l, int r, int ql, int qr, ll value){
    if (ql > r || qr < l){
        return;
    }
    if (ql <= l && r <= qr){
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

ll query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return LLONG_MIN;
    }
    if (ql <= l && r <= qr){
        return seg[sit];
    }
    push(sit);
    int mid = (l + r) / 2;
    return std::max(query(sit << 1, l, mid, ql, qr), query(sit << 1 | 1, mid + 1, r, ql, qr));
}

int h[N], b[N];
ll dp[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &h[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    std::vector <std::tuple <int, int, int, int>> stack;
    for (int i = 1; i <= n; ++ i){
        while (!stack.empty()){
            auto [l, r, height, value] = stack.back();
            if (height < h[i]){
                break;
            }
            stack.pop_back();
            add(1, 0, MAX - 1, l, r, b[i] - value);
        }
        int x = stack.empty() ? 0 : std::get <1>(stack.back()) + 1;
        stack.emplace_back(x, i - 1, h[i], b[i]);
        add(1, 0, MAX - 1, i - 1, i - 1, b[i]);
        dp[i] = query(1, 0, MAX - 1, 0, i - 1);
        add(1, 0, MAX - 1, i, i, dp[i]);
    }
    printf("%lld\n", dp[n]);
    return 0;
}