//
// Created by  on 2022/1/12.
//

//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 100010;

std::set <piii> e1[N], e2[N];
std::set <piii> all;
std::map <pii, int> value;
std::multiset <ll> type1;
ll ans_type1[N];

std::vector <piii> get_first(std::set <piii> &set, int num){
    std::vector <piii> result;
    auto it = set.begin();
    while (it != set.end() && int(result.size()) < num){
        result.emplace_back(*it);
        ++ it;
    }
    return result;
}

/*std::vector <piii> get_first(std::map <piii, int> &set, int num){
    std::vector <piii> result;
    auto it = set.begin();
    while (it != set.end() && int(result.size()) < num){
        result.emplace_back(it -> first);
        ++ it;
    }
    return result;
}*/

void process(piii p){
    auto [w, u, v] = p;
    if (!e1[u].count(p) || !e1[v].count(p)){
        return;
    }
    if (all.count(p)){
        all.erase(p);
    }
    else{
        all.emplace(p);
    }
}

void operate(int u, int v, int w){
    if (u > v){
        std::swap(u, v);
    }
    int type = w == -1 ? 1 : 0;
    if (type == 1){
        w = value[{u, v}];
        value.erase({u, v});
    }
    else{
        value[{u, v}] = w;
    }
    std::set <piii> to_process;
    for (int i: {u, v}){
        if (e1[i].size() == 3){
            auto it = type1.find(ans_type1[i]);
            type1.erase(it);
        }
        for (auto p : e1[i]){
            to_process.emplace(p);
        }
    }
    for (auto p : to_process){
        process(p);
    }
    for (int i: {u, v}){
        piii p = {w, u, v};
        if (type == 1){
            if (e2[i].count(p)){
                e2[i].erase(p);
            }
            else{
                e1[i].erase(p);
                if (!e2[i].empty()){
                    auto it = e2[i].begin();
                    e1[i].emplace(*it);
                    e2[i].erase(it);
                }
            }
        }
        else{
            e1[i].emplace(p);
            if (e1[i].size() == 4){
                auto it = std::prev(e1[i].end());
                e2[i].emplace(*it);
                e1[i].erase(it);
            }
        }
    }
    for (int i: {u, v}){
        ans_type1[i] = 0;
        for (auto p : e1[i]){
            to_process.emplace(p);
            ans_type1[i] += std::get <0>(p);
        }
        if (e1[i].size() == 3){
            type1.emplace(ans_type1[i]);
        }
    }
    for (auto p : to_process){
        process(p);
    }
}

ll getans(){
    ll ans = LLONG_MAX;
    if (!type1.empty()){
        ans = std::min(ans, *(type1.begin()));
    }
    std::vector <piii> vec = get_first(all, 8);
    if (!vec.empty()){
        auto [w, u, v] = vec[0];
        for (auto [w1, u1, v1] : e1[u]){
            for (auto [w2, u2, v2] : e1[v]){
                int other1 = u1 ^ v1 ^ u;
                int other2 = u2 ^ v2 ^ v;
                if (other1 != v && other2 != u && other1 != other2){
                    ans = std::min(ll(w1) + w2, ans);
                }
            }
        }
        int sz = vec.size();
        for (int i = 1; i < sz; ++ i){
            auto [w1, u1, v1] = vec[i];
            if (u1 != u && u1 != v && v1 != u && v1 != v){
                ans = std::min(ll(w) + w1, ans);
            }
        }
    }
    return ans;
}

void solve(){
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++ i){
        int u, v, w;
        std::cin >> u >> v >> w;
        operate(u, v, w);
    }
    std::cout << getans() << "\n";
    int q;
    std::cin >> q;
    while (q --){
        int type;
        std::cin >> type;
        if (type == 0){
            int u, v;
            std::cin >> u >> v;
            operate(u, v, -1);
        }
        else if (type == 1){
            int u, v, w;
            std::cin >> u >> v >> w;
            operate(u, v, w);
        }
        std::cout << getans() << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}