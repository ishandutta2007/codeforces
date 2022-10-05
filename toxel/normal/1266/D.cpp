#include <bits/stdc++.h>

using ll = long long;
const int N = 100010;

struct Ans{
    int u, v;
    ll w;
};

ll a[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a[v] += w;
        a[u] -= w;
    }
    std::queue <int> queue1, queue2;
    for (int i = 1; i <= n; ++ i){
        if (a[i] < 0){
            queue1.push(i);
        }
        else if (a[i] > 0){
            queue2.push(i);
        }
    }
    std::vector <Ans> ans;
    while (!queue1.empty() || !queue2.empty()){
        int u = queue1.front(), v = queue2.front();
        ll diff = std::min(-a[u], a[v]);
        ans.push_back({u, v, diff});
        a[u] += diff, a[v] -= diff;
        if (a[u] == 0){
            queue1.pop();
        }
        if (a[v] == 0){
            queue2.pop();
        }
    }
    printf("%d\n", int(ans.size()));
    for (auto u : ans){
        printf("%d %d %lld\n", u.u, u.v, u.w);
    }
    return 0;
}