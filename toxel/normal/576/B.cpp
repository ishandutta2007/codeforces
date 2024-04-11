#include<bits/stdc++.h>

const int N = 100010;
typedef std::pair <int, int> pii;

int p[N];
int cnt[N];
bool vis[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++ i){
        if (vis[i]) continue;
        int x = i, cnt = 0;
        while (true){
            ++ cnt;
            vis[x] = true;
            x = p[x];
            if (x == i) break;
        }
        ::cnt[i] = cnt;
    }
    for (int i = 1; i <= n; ++ i){
        if (cnt[i] == 1){
            puts("YES");
            for (int j = 1; j <= n; ++ j){
                if (i == j) continue;
                printf("%d %d\n", i, j);
            }
            return 0;
        }
    }

    std::vector <pii> ans;
    int p1 = -1, p2 = -1;
    for (int i = 1; i <= n; ++ i){
        if (cnt[i] == 2){
            p1 = i, p2 = p[i];
        }
    }
    ans.push_back({p1, p2});
    if (p1 == -1){
        puts("NO");
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        if (i == p1 || i == p2 || cnt[i] == 0) continue;
        if (cnt[i] & 1){
            puts("NO");
            return 0;
        }
        int x = i;
        while (true){
            ans.push_back({x, p1});
            std::swap(p1, p2);
            x = p[x];
            if (x == i) break;
        }
    }
    puts("YES");
    for (auto u : ans){
        printf("%d %d\n", u.first, u.second);
    }
    return 0;
}