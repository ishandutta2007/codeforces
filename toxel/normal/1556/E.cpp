#include <bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
using ll = long long;

ll a[N], b[N];
ll pre[N], seg[MAX << 1], seg1[MAX << 1];

ll query(int l, int r){
    ll ret = LLONG_MAX;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::min(ret, seg[l ++]);
        if (r & 1) ret = std::min(ret, seg[-- r]);
    }
    return ret;
}

ll query1(int l, int r){
    ll ret = LLONG_MIN;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::max(ret, seg1[l ++]);
        if (r & 1) ret = std::max(ret, seg1[-- r]);
    }
    return ret;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &b[i]);
    }
    for (int i = 1; i <= n; ++ i){
        a[i] -= b[i];
    }
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + a[i];
        seg[i + MAX] = pre[i];
        seg1[i + MAX] = pre[i];
    }
    for (int i = MAX - 1; i; -- i){
        seg[i] = std::min(seg[i << 1], seg[i << 1 | 1]);
        seg1[i] = std::max(seg1[i << 1], seg1[i << 1 | 1]);
    }
    while (q --){
        int l, r;
        scanf("%d%d", &l, &r);
        ll sum = pre[r] - pre[l - 1];
        if (sum != 0){
            puts("-1");
            continue;
        }
        ll max = query(l, r);
        ll max1 = query1(l, r);
        if (max1 - pre[l - 1] > 0){
            puts("-1");
            continue;
        }
        printf("%lld\n", -(max - pre[l - 1]));
    }
    return 0;
}