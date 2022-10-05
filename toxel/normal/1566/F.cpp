#include <bits/stdc++.h>

const int N = 500010;
using pii = std::pair <int, int>;
using ll = long long;
const ll INF = 1e15;


int a[N];
int l[N], r[N];
ll dp[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    for (int i = 0; i < m; ++ i){
        scanf("%d%d", &l[i], &r[i]);
    }
    std::vector <pii> vec;
    for (int i = 0; i < m; ++ i){
        int pos = std::lower_bound(a, a + n, l[i]) - a;
        if (pos != n && a[pos] <= r[i]){
            continue;
        }
        vec.emplace_back(l[i], -r[i]);
    }
    std::sort(vec.begin(), vec.end());
    std::vector <pii> nvec;
    for (auto p : vec){
        while (!nvec.empty() && nvec.back().second >= -p.second){
            nvec.pop_back();
        }
        nvec.emplace_back(p.first, -p.second);
    }
    vec.swap(nvec);
    if (vec.empty()){
        puts("0");
        return;
    }
    for (int i = 0; i < n; ++ i){
        vec.emplace_back(a[i], INT_MIN);
    }
    std::sort(vec.begin(), vec.end());
    int sz = vec.size();
    int last_point = -1;
    auto get_dp = [&](int pos){
        if (pos == -1){
            return 0ll;
        }
        return dp[pos];
    };
    auto get_type = [&](int pos){
        return vec[pos].first > vec[pos].second;
    };
    for (int i = 0; i <= sz; ++ i){
        dp[i] = INF;
    }
    // for (auto u : vec){
    //     printf("%d %d\n", u.first, u.second);
    // }
    ll pre_1 = LLONG_MAX, pre_2 = LLONG_MAX;
    ll pre_3 = LLONG_MAX, pre_4 = LLONG_MAX;
    for (int i = 0; i < sz; ++ i){
        int type = get_type(i);
        if (last_point == -1 && type == 0){
            dp[i] = INF;
        }
        else{
            if (type == 1){
                if (i == 0){
                    dp[i] = 0;
                }
                else{
                    dp[i] = dp[i - 1];
                }
                if (pre_1 != LLONG_MAX){
                    dp[i] = std::min(dp[i], pre_1 + vec[i].first);
                    pre_4 = std::min(pre_4, pre_1 + vec[i].first - 2ll * vec[i].first);
                    pre_3 = std::min(pre_3, pre_2 + 2ll * vec[i].first - vec[i].first);
                }
                pre_3 = std::min(pre_3, get_dp(i - 1) - vec[i].first);
            }
            else{
                dp[i] = std::min(dp[i], vec[i].first + pre_3);
                if (pre_4 != LLONG_MAX){
                    dp[i] = std::min(dp[i], 2ll * vec[i].first + pre_4);
                }
            }
        }
        if (type == 1){
            last_point = i;
        }
        else{
            pre_1 = std::min(pre_1, -1ll * vec[i].second + get_dp(i - 1));
            pre_2 = std::min(pre_2, -2ll * vec[i].second + get_dp(i - 1));
        }
    }
    printf("%lld\n", dp[sz - 1]);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}