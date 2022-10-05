#include<bits/stdc++.h>

const int N = 1000010;
typedef long long ll;

bool vis[N];
int a[N], pre[N];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, x; i < m; ++ i){
        scanf("%d", &x);
        vis[x] = true;
    }
    if (vis[0]){
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= k; ++ i){
        scanf("%d", &a[i]);
    }
    int max = 0, now = 0, pre = 0;
    for (int i = 0; i < n; ++ i){
        if (vis[i]){
            ++ now;
            max = std::max(max, now);
        }
        else{
            now = 0;
            pre = i;
        }
        ::pre[i] = pre;
    }
    ll min = LLONG_MAX;
    for (int i = max + 1; i <= k; ++ i){
        int now = 0, cnt = 0;
        while (now < n){
            now = ::pre[now];
            ++ cnt;
            now += i;
        }
        min = std::min(min, 1ll * cnt * a[i]);
    }
    if (min == LLONG_MAX){
        min = -1;
    }
    printf("%lld\n", min);
    return 0;
}