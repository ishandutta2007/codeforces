#include <bits/stdc++.h>

const int N = 100001;

int min[N];
std::vector <int> prime;

int query(int type, int a){
    printf("%c %d\n", char(type + 'A'), a);
    fflush(stdout);
    if (type == 2){
        return 0;
    }
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.emplace_back(i);
        }
        for (auto u : prime){
            if (i * u >= N) break;
            min[i * u] = u;
            if (i % u == 0) break;
        }
    }
    for (auto u : prime){
        if (1ll * u * u <= n){
            query(1, u);
        }
    }
    int tot = query(0, 1) - 1;
    for (auto u : prime){
        if (u <= n && 1ll * u * u > n){
            -- tot;
        }
    }
    int ans = 1;
    if (tot){
        std::vector<int> vec;
        for (auto u : prime){
            if (u > n){
                break;
            }
            if (1ll * u * u <= n){
                int cur = u;
                while (true){
                    int cnt = query(0, cur);
                    if (!cnt){
                        break;
                    }
                    ans *= u;
                    if (1ll * cur * u > n){
                        break;
                    }
                    cur *= u;
                }
            }
            else{
                if (query(0, u) == 2){
                    ans *= u;
                }
            }
        }
    }
    else{
        std::vector<int> vec;
        for (auto u : prime){
            if (1ll * u * u > n && u <= n){
                vec.emplace_back(u);
            }
        }
        int cur = 0, sz = vec.size();
        int cnt = 0;
        while (cur < sz){
            int mid = (cur + sz) / 2;
            for (int i = cur; i <= mid; ++ i){
                query(1, vec[i]);
                ++ cnt;
            }
            if (query(0, 1) + cnt > sz + 1){
                for (int i = cur; i <= mid; ++ i){
                    if (query(0, vec[i])){
                        ans = vec[i];
                        break;
                    }
                }
                break;
            }
            cur = mid + 1;
        }
    }
    query(2, ans);
    return 0;
}