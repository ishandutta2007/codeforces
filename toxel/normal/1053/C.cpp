#include<bits/stdc++.h>

typedef long long ll;
const int moder = (int) 1e9 + 7;
const int N = 200010;

ll c[2][N];
int a[N], w[N];

void add(ll *c, int sit, int x){
    for ( ; sit < N; sit += sit & -sit){
        c[sit] += x;
    }
}

ll query(ll *c, int sit){
    ll ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

ll query(ll *c, int l, int r){
    return query(c, r) - query(c, l - 1);
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        a[i] -= i;
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &w[i]);
        add(c[0], i, w[i]);
        add(c[1], i, 1ll * w[i] * a[i] % moder);
    }
    while (q --){
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0){
            add(c[0], -x, y - w[-x]);
            add(c[1], -x, 1ll * (y - w[-x]) * a[-x] % moder);
            w[-x] = y;
            continue;
        }
        ll sum = query(c[0], x, y);
        int left = x, right = y;
        while (left < right){
            int mid = left + right >> 1;
            if (query(c[0], x, mid) << 1 >= sum){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        int sit = left;
        int value = a[sit];
        int ans = (query(c[1], sit + 1, y) % moder - 1ll * value * (query(c[0], sit + 1, y) % moder)) % moder;
        ans = (ans - query(c[1], x, sit) % moder + 1ll * value * (query(c[0], x, sit) % moder)) % moder;
        ans += ans < 0 ? moder : 0;
        printf("%d\n", ans);
    }
    return 0;
}