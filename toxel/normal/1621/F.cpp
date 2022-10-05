#include <bits/stdc++.h>

const int N = 100010;
using pii = std::pair <int, int>;
using ll = long long;

char s[N];
bool has10[N], has11[N];

void solve(){
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    for (int i = 0; i <= n + 1; ++ i){
        has10[i] = has11[i] = false;
    }
    scanf("%s", s);
    int cnt1 = 0;
    for (int i = 0; i < n - 1; ++ i){
        if (s[i] == s[i + 1] && s[i] == '1'){
            ++ cnt1;
        }
    }
    for (int i = 0; i < n; ++ i){
        if ((i > 0 && has10[i - 1]) || s[i] == '1'){
            has10[i] = true;
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        if ((i < n - 1 && has11[i + 1]) || s[i] == '1'){
            has11[i] = true;
        }
    }
    std::vector <pii> vec;
    int tmp = 0;
    for (int i = 0; i <= n; ++ i){
        if (i < n && s[i] == '0'){
            ++ tmp;
        }
        else{
            if (tmp == 0){
                continue;
            }
            if (has10[i - 1] && has11[i - 1]){
                vec.emplace_back(tmp, tmp);
            }
            else{
                vec.emplace_back(INT_MAX, tmp);
            }
            tmp = 0;
        }
    }
    ll ans = 0;
    for (int start = 0; start < 2; ++ start){
        int cur = start;
        std::multiset <pii> set;
        for (auto u : vec){
            set.emplace(u);
        }
        ll sum = 0;
        int ccnt1 = cnt1;
        while (true){
            if (cur == 0){
                if (ccnt1 <= 0){
                    break;
                }
                -- ccnt1;
                sum += b;
                ans = std::max(ans, sum);
            }
            else{
                if (set.empty()){
                    break;
                }
                auto u = set.lower_bound({2, 2});
                if (u != set.end() && u -> first == u -> second && u -> second >= 2){
                    ans = std::max(ans, sum + a);
                }
                u = set.lower_bound({INT_MAX, 2});
                if (u != set.end() && u -> second >= 2){
                    ans = std::max(ans, sum + a);
                }
                if (ccnt1 <= 0){
                    pii p = *(set.begin());
                    set.erase(set.begin());
                    if (p.first == 1 && p.second == 1){
                        ccnt1 += 1;
                        sum -= c;
                    }
                    else{
                        break;
                    }
                }
                else{
                    u = set.lower_bound({2, 2});
                    if (u != set.end() && u -> first == u -> second && u -> second >= 2){
                        sum += a;
                        pii p = *u;
                        set.erase(u);
                        set.emplace(p.first - 1, p.second - 1);
                    }
                    else{
                        u = set.lower_bound({INT_MAX, 2});
                        if (u != set.end() && u -> second >= 2){
                            sum += a;
                            pii p = *u;
                            set.erase(u);
                            set.emplace(p.first, p.second - 1);
                        }
                        else{
                            u = set.begin();
                            pii p = *u;
                            set.erase(u);
                            assert(p.second == 1);
                            if (p.first == 1 && p.second == 1){
                                ++ ccnt1;
                            }
                            sum -= c;
                        }
                    }
                }
                ans = std::max(ans, sum);
            }
            cur ^= 1;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}