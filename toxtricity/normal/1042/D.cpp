#include<bits/stdc++.h>

typedef long long ll;

const int N = 200010;

ll pre[N];
int c[N];
ll x[N];

void add(int sit, int value){
    for (++ sit; sit < N; sit += sit & -sit){
        c[sit] += value;
    }
}

int query(int sit){
    if (sit < 0) return 0;
    int ret = 0;
    for (++ sit; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

int main(){
    int n;
    ll t;
    scanf("%d%lld", &n, &t);
    for (int i = 1, x; i <= n; ++ i){
        scanf("%d", &x);
        pre[i] = pre[i - 1] + x;
        ::x[i] = pre[i];
    }
    std::sort(x, x + n + 1);
    int cnt = std::unique(x, x + n + 1) - x;
    ll ans = 0;
    add(std::lower_bound(x, x + cnt, pre[n]) - x, 1);
    for (int i = n - 1; i >= 0; -- i){
        ans += query(std::lower_bound(x, x + cnt, pre[i] + t) - x - 1);
        add(std::lower_bound(x, x + cnt, pre[i]) - x, 1);
    }
    printf("%lld\n", ans);
}