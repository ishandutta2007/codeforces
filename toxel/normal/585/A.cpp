#include<bits/stdc++.h>

const int N = 4010;
typedef long long ll;

ll v[N], d[N], p[N];
bool vis[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld%lld%lld", &v[i], &d[i], &p[i]);
        vis[i] = true;
    }
    for (int i = 0; i < n; ++ i){
        if (!vis[i]) continue;
        ll nowsub = v[i], nowsub1 = 0;
        for (int j = i + 1; j < n; ++ j){
            if (!vis[j]) continue;
            p[j] -= nowsub1 + nowsub;
            if (nowsub > 0){
                -- nowsub;
            }
            if (p[j] < 0){
                vis[j] = false;
                nowsub1 += d[j];
            }
        }
    }
    std::vector <int> ans;
    for (int i = 0; i < n; ++ i){
        if (vis[i]){
            ans.push_back(i);
        }
    }
    printf("%d\n", (int) ans.size());
    for (int i = 0, sz = ans.size(); i < sz; ++ i){
        printf("%d%c", ans[i] + 1, " \n"[i == sz - 1]);
    }
    return 0;
}