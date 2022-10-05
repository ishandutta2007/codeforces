#include<bits/stdc++.h>

const int N = 1010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    std::unordered_map <int, int> map;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        ans += a[i] == 0;
        ++ map[a[i]];
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (i == j) continue;
            if (!a[i] && !a[j]) continue;
            std::vector <int> rollback;
            -- map[a[i]], -- map[a[j]];
            rollback.push_back(a[i]);
            rollback.push_back(a[j]);
            int x = a[i], y = a[j];
            int cnt = 2;
            while (true){
                int tmp = x + y;
                if (std::abs(tmp) > 1000000000){
                    break;
                }
                if (!map.count(tmp) || map[tmp] == 0){
                    break;
                }
                ++ cnt;
                x = y;
                y = tmp;
                -- map[tmp];
                rollback.push_back(tmp);
            }
            for (auto u : rollback){
                ++ map[u];
            }
            ans = std::max(ans, cnt);
        }
    }
    printf("%d\n", ans);
    return 0;
}