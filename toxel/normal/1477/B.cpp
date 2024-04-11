#include <bits/stdc++.h>

const int N = 200010;
using pii = std::pair <int, int>;

char s[N], t[N];
int l[N], r[N];

void solve(){
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s%s", s, t);
    for (int i = 0; i < q; ++ i){
        scanf("%d%d", &l[i], &r[i]);
        -- l[i], -- r[i];
    }
    std::map <pii, int> map;
    for (int i = 0; i < n; ++ i){
        map[{i, i}] = t[i] - '0';
    }
    for (int i = q - 1; i >= 0; -- i){
        std::vector <std::pair <pii, int>> to_insert;
        auto u = map.lower_bound({l[i], r[i]});
        if (u != map.begin()){
            u = std::prev(u);
        }
        int sum = 0;
        while (u != map.end() && u -> first.first <= r[i]){
            int ll = std::max(l[i], u -> first.first);
            int rr = std::min(r[i], u -> first.second);
            if (ll > rr){
                u = std::next(u);
                continue;
            }
            sum += (rr - ll + 1) * u -> second;
            if (u -> first.first < l[i]){
                to_insert.push_back({{u -> first.first, l[i] - 1}, u -> second});
            }
            if (u -> first.second > r[i]){
                to_insert.push_back({{r[i] + 1, u -> first.second}, u -> second});
            }
            u = map.erase(u);
        }
        int tot = r[i] - l[i] + 1;
        if (sum * 2 == tot){
            puts("NO");
            return;
        }
        if (sum < tot - sum){
            to_insert.push_back({{l[i], r[i]}, 0});
        }
        else{
            to_insert.push_back({{l[i], r[i]}, 1});
        }
        for (auto u : to_insert){
            map[u.first] = u.second;
        }
    }
    for (auto u : map){
        for (int i = u.first.first; i <= u.first.second; ++ i){
            if (s[i] != '0' + u.second){
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}