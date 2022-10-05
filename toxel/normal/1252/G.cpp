#include <bits/stdc++.h>

const int N = 400010;
const int BIT = 20;
using ll = long long;

ll w[N], fa[N][BIT], fa1[N][BIT];
ll max[N][BIT], sum[N][BIT], cnt[N][BIT];

int main(){
    int test;
    scanf("%d", &test);
    ll last = 0;
    int pcnt = 1;
    for (int i = 0; i < BIT; ++ i){
        cnt[1][i] = 1;
    }
    while (test --){
        int type;
        ll p, q;
        scanf("%d%lld%lld", &type, &p, &q);
        p ^= last, q ^= last;
        if (type == 1){
            int u = ++ pcnt;
            fa[u][0] = p;
            for (int i = 1; i < BIT; ++ i){
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
            }
            max[u][0] = q;
            for (int i = 1; i < BIT; ++ i){
                max[u][i] = std::max(max[u][i - 1], max[fa[u][i - 1]][i - 1]);
            }
            int now = p;
            for (int i = BIT - 1; i >= 0; -- i){
                if (max[now][i] < q){
                    now = fa[now][i];
                }
            }
            fa1[u][0] = now;
            for (int i = 1; i < BIT; ++ i){
                fa1[u][i] = fa1[fa1[u][i - 1]][i - 1];
            }
            sum[u][0] = q;
            cnt[u][0] = 1;
            for (int i = 1; i < BIT; ++ i){
                sum[u][i] = sum[u][i - 1] + sum[fa1[u][i - 1]][i - 1];
                cnt[u][i] = cnt[u][i - 1] + cnt[fa1[u][i - 1]][i - 1];
            }
        }
        else{
            int ans = 0;
            for (int i = BIT - 1; i >= 0; -- i){
                if (sum[p][i] <= q){
                    q -= sum[p][i];
                    ans += cnt[p][i];
                    p = fa1[p][i];
                }
            }
            printf("%d\n", ans);
            last = ans;
        }
    }
    return 0;
}