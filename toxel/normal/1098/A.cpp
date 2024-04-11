#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

std::vector <int> e[N];
int s[N], p[N], dep[N];

void dfs(int u, int fa){
    int left = s[fa];
    int right = INT_MAX;
    for (auto v : e[u]){
        dfs(v, u);
        right = std::min(right, s[v]);
    }
    if (s[u] != -1){
        return;
    }
    if (left > right){
        puts("-1");
        exit(0);
    }
    s[u] = right == INT_MAX ? left : right;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++ i){
        scanf("%d", &p[i]);
        e[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &s[i]);
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += s[i] - s[p[i]];
    }
    printf("%lld\n", ans);
    return 0;
}