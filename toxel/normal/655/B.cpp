#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int a[N], c[N], inv[N];

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

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        a[i] = i;
    }
    for (int i = 0; i < std::min(k, n >> 1); ++ i){
        std::swap(a[i + 1], a[n - i]);
    }
    for (int i = 1; i <= n; ++ i){
        inv[a[i]] = i;
    }
    ll ans = 0;
    for (int i = n; i >= 1; -- i){
        ans += query(inv[i]);
        add(inv[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}