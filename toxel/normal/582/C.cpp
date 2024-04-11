#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int a[N];
ll ans[N];
bool vis[N];
int tmp[N], pre[N];
std::vector <int> vec[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++ i){
        vec[std::__gcd(i, n)].push_back(i);
    }
    ll ret = 0;
    for (int i = 1; i < n; ++ i){
        if (n % i) continue;
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < i; ++ j){
            int sz = n / i;
            int max = 0;
            for (int k = 0; k < sz; ++ k){
                max = std::max(max, a[k * i + j]);
            }
            for (int k = 0; k < sz; ++ k){
                if (max == a[k * i + j]){
                    vis[k * i + j] = true;
                }
            }
        }
        int cnt = 0, pre = -1;
        for (int j = 0; j <= n; ++ j){
            if (!vis[j]){
                int x = j - pre - 1;
                pre = j;
                if (x){
                    tmp[cnt ++] = x;
                }
            }
        }
        if (cnt == 1 && vis[0] && vis[n - 1]){
            for (auto u : vec[i]){
                ret += n;
            }
            continue;
        }
        if (vis[0] && vis[n - 1]){
            tmp[0] += tmp[cnt - 1];
            -- cnt;
        }
        std::sort(tmp, tmp + cnt, std::greater <int>());
        for (int i = 0; i < cnt; ++ i){
            ::pre[i] = i ? ::pre[i - 1] + tmp[i] : tmp[0];
        }
        for (auto u : vec[i]){
            int sit = std::upper_bound(tmp, tmp + cnt, u, [](int p1, int p2){return p1 > p2;}) - tmp;
            if (!sit) continue;
            ret += ::pre[sit - 1] - sit * (u - 1);
        }
    }
    printf("%lld\n", ret);
    return 0;
}