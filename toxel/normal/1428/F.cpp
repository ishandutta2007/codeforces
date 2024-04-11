#include <bits/stdc++.h>

const int N = 500010;
const int MAX = 1 << 19;
using ll = long long;

char s[N];
std::vector<int> process[N];
ll sum[N];
ll seg[MAX << 1], max[MAX << 1], min[MAX << 1], lazy[MAX << 1];
int right[N];

void push(int sit, int l, int r){
    if (!lazy[sit]){
        return;
    }
    int length = (r - l + 1) / 2;
    max[sit << 1] = max[sit << 1 | 1] = lazy[sit];
    min[sit << 1] = min[sit << 1 | 1] = lazy[sit];
    seg[sit << 1] = seg[sit << 1 | 1] = lazy[sit] * length;
    lazy[sit << 1] = lazy[sit << 1 | 1] = lazy[sit];
    lazy[sit] = 0;
}

void pull(int sit){
    seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
    max[sit] = std::max(max[sit << 1], max[sit << 1 | 1]);
    min[sit] = std::min(min[sit << 1], min[sit << 1 | 1]);
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql > r || qr < l){
        return;
    }
    if (value <= min[sit]){
        return;
    }
    if (ql <= l && qr >= r && value >= max[sit]){
        seg[sit] = 1ll * (r - l + 1) * value;
        max[sit] = min[sit] = value;
        lazy[sit] = value;
        return;
    }
    push(sit, l, r);
    int mid = (l + r) / 2;
    add(sit << 1, l, mid, ql, qr, value);
    add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    pull(sit);
}

ll query(int sit, int l, int r, int ql, int qr){
    if (ql > r || qr < l){
        return 0;
    }
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit, l, r);
    int mid = (l + r) / 2;
    return query(sit << 1, l, mid, ql, qr) + query(sit << 1 | 1, mid + 1, r, ql, qr);
}

int main(){
    for (int i = 1; i < N; ++ i){
        sum[i] = sum[i - 1] + i;
    }
    for (int i = 1; i < N; ++ i){
        sum[i] += sum[i - 1];
    }
    int n;
    scanf("%d%s", &n, s);
    /*scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        s[i] = '0' + rand() % 2;
    }*/
    int pre = -1;
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        if (i == n - 1 || s[i] != s[i + 1]){
            int l = pre + 1, r = i;
            if (s[i] == '1'){
                ans += sum[r - l + 1];
                process[l].emplace_back(r);
                for (int j = l + 1; j <= r; ++ j){
                    process[j].emplace_back(r);
                }
                for (int j = l; j < r; ++ j){
                    process[l].emplace_back(j);
                }
            }
            pre = i;
        }
    }
    right[n] = n;
    for (int i = n - 1; i >= 0; -- i){
        if (s[i] == '0'){
            right[i] = i;
        }
        else{
            right[i] = right[i + 1];
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        for (auto u : process[i]){
            add(1, 0, MAX - 1, u, n - 1, u - i + 1);
        }
        if (right[i] < n){
            ans += query(1, 0, MAX - 1, right[i], n - 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}