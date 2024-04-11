//
// Created by  on 2022/2/2.
//

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

// You should pay great attention to Case: n = 1
class PQTree{
public:
    int n, root;
    bool failed;
    std::vector <int> type, col, pool;
    std::vector <std::vector <int>> e;

    explicit PQTree(int sz):n(sz), failed(false){
        // assert(n > 1);
        sz = 10 * sz + 10;
        type.resize(sz);
        col.resize(sz, 1);
        for (int i = sz - 1; i >= n + 2; -- i){
            pool.emplace_back(i);
        }
        e.resize(sz);
        root = n + 1;
        e[root].resize(n);
        for (int i = 0; i < n; ++ i){
            e[root][i] = i + 1;
        }
    }

    void get_col(int u){
        if (u > n){
            col[u] = 0;
        }
        for (auto v : e[u]){
            get_col(v);
            col[u] |= col[v];
        }
    }

    int new_node(int cur_type, int cur_col){
        int res = pool.back();
        pool.pop_back();
        type[res] = cur_type;
        col[res] = cur_col;
        std::vector <int>().swap(e[res]);
        return res;
    }

    std::vector <int> split(int u){
        if (failed){
            return {};
        }
        if (col[u] == 1 || col[u] == 2){
            return {u};
        }
        if ((col[e[u].front()] ^ 1) > (col[e[u].back()] ^ 1)){
            std::reverse(e[u].begin(), e[u].end());
        }
        std::vector <int> els[4];
        for (auto v : e[u]){
            els[col[v]].emplace_back(v);
        }
        if (int(els[3].size()) >= 2){
            failed = true;
            return {};
        }
        std::vector <int> ret;
        if (type[u] == 0){ // P node
            if (!els[1].empty()){
                int n1 = new_node(0, 1);
                e[n1] = els[1];
                ret.emplace_back(n1);
            }
            if (!els[3].empty()){ // must be only one
                for (auto v : split(els[3][0])){
                    ret.emplace_back(v);
                }
            }
            if (!els[2].empty()){
                int n2 = new_node(0, 2);
                e[n2] = els[2];
                ret.emplace_back(n2);
            }
            return ret;
        }
        // Q node
        int sz = e[u].size();
        for (int i = 0; i < sz - 1; ++ i){
            if ((col[e[u][i]] ^ 1) > (col[e[u][i + 1]] ^ 1)){
                failed = true;
                return {};
            }
        }
        for (auto v : els[1]){
            ret.emplace_back(v);
        }
        if (!els[3].empty()){ // must be only one
            for (auto v : split(els[3][0])){
                ret.emplace_back(v);
            }
        }
        for (auto v : els[2]){
            ret.emplace_back(v);
        }
        return ret;
    }

    void dfs(int u){
        if (col[u] != 3 || failed){
            return;
        }
        if (type[u] == 0){ // P node
            std::vector <int> els[4];
            for (auto v : e[u]){
                els[col[v]].emplace_back(v);
            }
            if (int(els[3].size()) > 2){
                failed = true;
                return;
            }
            if (int(els[3].size()) == 1 && els[2].empty()){
                dfs(els[3][0]);
                return;
            }
            e[u].clear();
            for (auto v : els[1]){
                e[u].emplace_back(v);
            }
            if (els[3].empty()){ // white and black must not be empty
                int n2 = new_node(0, 2);
                e[n2] = els[2];
                e[u].emplace_back(n2);
                return;
            }
            int n3 = new_node(1, 3);
            e[n3].emplace_back(els[3][0]);
            if (!els[2].empty()){
                int n2 = new_node(0, 2);
                e[n2] = els[2];
                e[n3].emplace_back(n2);
            }
            if (int(els[3].size()) == 2){
                e[n3].emplace_back(els[3][1]);
            }
            e[u].emplace_back(n3);
            dfs(n3);
            return;
        }
        // Q node
        int sz = e[u].size();
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < sz; ++ i){ // there must be at least one
            if (col[e[u][i]] != 1){
                l = std::min(l, i);
                r = std::max(r, i);
            }
        }
        for (int i = l + 1; i <= r - 1; ++ i){
            if (col[e[u][i]] != 2){
                failed = true;
                return;
            }
        }
        if (l == r){
            dfs(e[u][l]);
            return;
        }
        std::vector <int> temp_e;
        for (int i = 0; i < sz; ++ i){
            if (i == l){
                std::vector <int> temp_temp_e = split(e[u][i]);
                for (auto v : temp_temp_e){
                    temp_e.emplace_back(v);
                }
            }
            else if (i == r){
                std::vector <int> temp_temp_e = split(e[u][i]);
                std::reverse(temp_temp_e.begin(), temp_temp_e.end());
                for (auto v : temp_temp_e){
                    temp_e.emplace_back(v);
                }
            }
            else{
                temp_e.emplace_back(e[u][i]);
            }
        }
        e[u].swap(temp_e);
    }

    void norm(int &u){
        if (int(e[u].size()) == 1){
            pool.emplace_back(u);
            u = e[u][0];
        }
        for (auto &v : e[u]){
            norm(v);
        }
    }

    // assume vec's elements are distinct
    void update(const std::vector <int> &vec){
        if (int(vec.size()) <= 1 || int(vec.size()) == n){
            return;
        }
        if (failed){
            return;
        }
        for (auto u : vec){
            col[u] = 2;
        }
        get_col(root);
        dfs(root);
        norm(root);
        for (auto u : vec){
            col[u] = 1;
        }
    }
};

std::vector <int> vec;

void dfs(int u, int n, PQTree &pqTree){
    if (u <= n){
        vec.emplace_back(u - 1);
    }
    for (auto v : pqTree.e[u]){
        dfs(v, n, pqTree);
    }
}

void solve(){
    int n;
    std::cin >> n;
    PQTree pqTree(n);
    std::vector <std::string> s(n);
    for (int i = 0; i < n; ++ i){
        std::cin >> s[i];
        std::vector <int> vec;
        for (int j = 0; j < n; ++ j){
            if (s[i][j] == '1'){
                vec.emplace_back(j + 1);
            }
        }
        pqTree.update(vec);
    }
    if (pqTree.failed){
        std::cout << "NO\n";
        return;
    }
    dfs(pqTree.root, n, pqTree);
    std::cout << "YES\n";
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            std::cout << s[i][vec[j]];
        }
        std::cout << '\n';
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

#endif //WORKSPACE_TEMPLATE_H