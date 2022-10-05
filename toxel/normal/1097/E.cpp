#include<bits/stdc++.h>

const int N = 100010;
const int M = 1 << 17;
int MAX;

int dp[N];
std::vector <std::vector <int>> ans;
int seg[M << 1];

void add(int sit, int value){
    seg[sit += MAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

int query(int l, int r){
    int ret = -1;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::max(ret, seg[l ++]);
        if (r & 1) ret = std::max(ret, seg[-- r]);
    }
    return ret;
}

void calc(std::vector <int> vec, int n){
    if (vec.empty()){
        return;
    }
    int x = std::max(0, (int) std::sqrt(vec.size() * 2) - 2);
    while (x * (x + 1) / 2 < (int) vec.size()){
        ++ x;
    }
    MAX = 1;
    while (MAX <= n){
        MAX <<= 1;
    }
    memset(seg, -1, sizeof(int) * MAX * 2);
    add(0, 0);
    int sz = vec.size();
    for (int i = 0; i < sz; ++ i){
        dp[i] = query(0, vec[i] - 1) + 1;
        add(vec[i], dp[i]);
    }
    int sit, max = 0;
    for (int i = 0; i < sz; ++ i){
        if (dp[i] > max){
            max = dp[i];
            sit = i;
        }
    }
    if (max >= x){
        std::vector <int> ret;
        while (true){
            ret.push_back(vec[sit]);
            if (dp[sit] == 1){
                break;
            }
            for (int i = sit - 1; ; -- i){
                if (dp[i] == dp[sit] - 1){
                    sit = i;
                    break;
                }
            }
        }
        std::reverse(ret.begin(), ret.end());
        std::vector <int> nvec;
        for (int i = 0, j = 0, sz1 = ret.size(); i < sz; ++ i){
            if (j < sz1 && vec[i] == ret[j]){
                ++ j;
                continue;
            }
            nvec.push_back(vec[i]);
        }
        ans.push_back(ret);
        calc(nvec, n);
        return;
    }
    std::vector <std::vector <int>> ans;
    for (int i = 0; i < sz; ++ i){
        if (ans.empty() || ans.back().back() < vec[i]){
            ans.push_back({});
            ans.back().push_back(vec[i]);
            continue;
        }
        auto u = std::upper_bound(ans.begin(), ans.end(), std::vector <int>(1, vec[i]),
                [&](const auto &v1, const auto &v2){return v1.back() < v2.back();});
        u -> push_back(vec[i]);
    }
    for (auto u : ans){
        ::ans.push_back(u);
    }
}

void solve(){
    std::vector <std::vector <int>>().swap(ans);
    int n;
    scanf("%d", &n);
    std::vector <int> vec(n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &vec[i]);
    }
    calc(vec, n); 
    printf("%d\n", (int) ans.size());
    for (auto &u : ans){
        printf("%d", (int) u.size());
        for (auto v : u){
            printf(" %d", v);
        }
        puts("");
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}