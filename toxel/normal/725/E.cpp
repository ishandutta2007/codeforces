#include<bits/stdc++.h>

const int N = 200010;

bool dp[N];
int a[N];

int main(){
    int c, n;
    scanf("%d%d", &c, &n);
    std::map <int, int> map;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        ++ map[a[i]];
    }
    for (int i = 1; i < c; ++ i){
        ++ map[i];
        int x = c;
        bool flag = true;
        typedef std::pair <int, int> pii;
        std::vector <pii> rollback;
        while (true){
            auto u = map.upper_bound(x);
            if (u == map.begin()){
                flag = x == 0;
                break;
            }
            -- u;
            x -= std::min(u -> second, x / u -> first) * u -> first;
            rollback.push_back(*u);
            map.erase(u);
        }
        if (!flag){
            printf("%d\n", i);
            return 0;
        }
        for (auto u : rollback){
            map[u.first] = u.second;
        }
        if (map[i] == 1){
            map.erase(i);
        }
        else{
            -- map[i];
        }
    }
    puts("Greed is good");
    return 0;
}