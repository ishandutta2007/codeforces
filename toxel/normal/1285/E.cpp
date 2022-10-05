#include <bits/stdc++.h>

const int N = 500010;
const int MAX = 1 << 19;

int l[N], r[N], c[N];
int pre[N], seg[MAX << 1];

void add(int sit, int value){
    seg[sit += MAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
    }
}

int query(int l, int r){
    int ret = 0;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret += seg[l ++];
        if (r & 1) ret += seg[-- r];
    }
    return ret;
}
void solve(){
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &l[i], &r[i]);
        l[i] = l[i] * 2;
        r[i] = r[i] * 2 + 1;
        c[cnt ++] = l[i];
        c[cnt ++] = r[i];
    }
    std::sort(c, c + cnt);
    cnt = std::unique(c, c + cnt) - c;
    int MMAX = 2 * n + 10;
    memset(pre, 0, sizeof(pre[0]) * MMAX);
    for (int i = 0; i < n; ++ i){
        l[i] = std::lower_bound(c, c + cnt, l[i]) - c + 1;
        r[i] = std::lower_bound(c, c + cnt, r[i]) - c + 1;
        ++ pre[l[i]];
        -- pre[r[i]];
    }
    for (int i = 1; i < MMAX; ++ i){
        pre[i] += pre[i - 1];
    }
    int cur = 1;
    for (int i = 0; i < MMAX - 1; ++ i){
        if (pre[i] == 0 && pre[i + 1] > 0){
            ++ cur;
        }
        if (pre[i] == 1 && pre[i + 1] > 1){
            add(i, 1);
        }
        else{
            add(i, 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        if (l[i] == r[i]){
            ans = std::max(ans, cur);
            continue;
        }
        int sum = query(l[i], r[i] - 1);
        int prev = pre[l[i] - 1], suf = pre[r[i]];
        int prev1 = pre[l[i]] - 1, suf1 = pre[r[i] - 1] - 1;
        if (prev == 0 && prev1 == 0){
            -- sum;
        }
        ans = std::max(ans, sum + cur);
    }
    printf("%d\n", ans - 1);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}