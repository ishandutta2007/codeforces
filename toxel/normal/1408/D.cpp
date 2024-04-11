#include <bits/stdc++.h>

const int N = 1000010;

std::vector<int> vec[N];
int a[N], b[N], c[N], d[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &c[i], &d[i]);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int x = c[j] - a[i] + 1, y = d[j] - b[i] + 1;
            if (x <= 0 || y <= 0){
                continue;
            }
            vec[x].emplace_back(y);
        }
    }
    int ans = INT_MAX;
    int cur = 0;
    for (int i = N - 1; i >= 0; -- i){
        ans = std::min(ans, cur + i);
        if (vec[i].empty()){
            continue;
        }
        cur = std::max(cur, *std::max_element(vec[i].begin(), vec[i].end()));
    }
    printf("%d\n", ans);
    return 0;
}