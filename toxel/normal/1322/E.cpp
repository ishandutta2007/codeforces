#include <bits/stdc++.h>

const int N = 500010;
std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());

struct Inter{
    int l, r;
    int type;

    Inter():l(0), r(0), type(0){}
    Inter(int l, int r, int type){
        if (l == r && type <= 1){
            type ^= l & 1;
            type += 2;
        }
        this -> l = l, this -> r = r, this -> type = type;
    }

    bool operator < (const Inter &i)const{
        return l == i.l ? r < i.r : l < i.l;
    }

    bool operator == (const Inter &i)const{
        return l == i.l && r == i.r && type == i.type;
    }

    int get_value(int pos){
        if (type <= 1){
            return type;
        }
        return (type - 2) ^ (pos & 1);
    }
};

int a[N], c[N];
std::vector<int> vec[N];
int ans[N];
int fa[N], right[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    fa[u] = v;
    right[v] = std::max(right[v], right[u]);
}

int main(){
    for (int i = 0; i < N; ++ i){
        fa[i] = right[i] = i;
    }
    int n;
    scanf("%d", &n);
    int begin = clock();
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        // a[i] = rnd() % 1'000'000'00;
        c[cnt ++] = a[i];
    }
    a[0] = a[1], a[n + 1] = a[n];
    std::sort(c, c + n);
    cnt = std::unique(c, c + n) - c;
    for (int i = 0; i <= n + 1; ++ i){
        a[i] = std::lower_bound(c, c + cnt, a[i]) - c;
        vec[a[i]].emplace_back(i);
    }
    int max = 0;
    std::map <int, int> map;
    std::set <Inter> set;
    set.insert({0, n + 1, 1});
    auto update = [&](int l, int r, int value){
        l = right[find(l)];
        while (l <= r){
            ans[l] = value;
            unite(l, l + 1);
            l = right[find(l + 1)];
        }
    };
    for (int i = 0; i < cnt; ++ i){
        std::vector<Inter> vec2;
        for (auto u : vec[i]){
            auto v = set.lower_bound(Inter(u + 1, INT_MIN, 0));
            std::vector<Inter> vec1;
            if (v != set.end()){
                vec1.emplace_back(*v);
                v = set.erase(v);
            }
            v = std::prev(v);
            vec1.emplace_back(*v);
            v = set.erase(v);
            if (v != set.begin()){
                vec1.emplace_back(*std::prev(v));
                set.erase(std::prev(v));
            }
            std::reverse(vec1.begin(), vec1.end());
            std::vector<Inter> stack;
            std::vector<Inter> queue;
            for (auto inter : vec1){
                if (inter.type >= 2){
                    int value = (inter.r - inter.l + 1 + 1) / 2;
                    auto w = map.find(value);
                    if (w != map.end() && w -> second == 1){
                        map.erase(w);
                    }
                    else{
                        -- w -> second;
                    }
                }
                if (inter.l <= u && u <= inter.r){
                    if (inter.l < u){
                        queue.emplace_back(inter.l, u - 1, inter.type);
                    }
                    queue.emplace_back(u, u, 0);
                    if (u < inter.r){
                        queue.emplace_back(u + 1, inter.r, inter.type);
                    }
                }
                else{
                    queue.emplace_back(inter);
                }
            }
            for (auto inter2 : queue){
                if (stack.empty()){
                    stack.emplace_back(inter2);
                    continue;
                }
                Inter inter1 = stack.back();
                stack.pop_back();
                if (inter1.type == inter2.type){
                    stack.emplace_back(inter1.l, inter2.r, inter1.type);
                    continue;
                }
                if (inter1.type <= 1 && inter2.type <= 1){
                    stack.emplace_back(inter1);
                    stack.emplace_back(inter2);
                    continue;
                }
                if (inter1.type >= 2 && inter2.type >= 2){
                    int r = inter1.get_value(inter1.r), l = inter2.get_value(inter2.l);
                    if (r == l){
                        if (inter1.l < inter1.r){
                            stack.emplace_back(inter1.l, inter1.r - 1, inter1.type);
                        }
                        stack.emplace_back(inter1.r, inter2.l, l);
                        if (inter2.l < inter2.r){
                            stack.emplace_back(inter2.l + 1, inter2.r, inter2.type);
                        }
                    }
                    else{
                        stack.emplace_back(inter1);
                        stack.emplace_back(inter2);
                    }
                    continue;
                }
                if (inter1.type <= 1){
                    int r = inter1.get_value(inter1.r), l = inter2.get_value(inter2.l);
                    if (r == l){
                        stack.emplace_back(inter1.l, inter2.l, l);
                        if (inter2.l < inter2.r){
                            stack.emplace_back(inter2.l + 1, inter2.r, inter2.type);
                        }
                    }
                    else{
                        stack.emplace_back(inter1);
                        stack.emplace_back(inter2);
                    }
                    continue;
                }
                int r = inter1.get_value(inter1.r), l = inter2.get_value(inter2.l);
                if (r == l){
                    if (inter1.l < inter1.r){
                        stack.emplace_back(inter1.l, inter1.r - 1, inter1.type);
                    }
                    stack.emplace_back(inter1.r, inter2.r, r);
                }
                else{
                    stack.emplace_back(inter1);
                    stack.emplace_back(inter2);
                }
            }
            for (auto inter : stack){
                set.insert(inter);
                vec2.emplace_back(inter);
                if (inter.type >= 2){
                    int value = (inter.r - inter.l + 1 + 1) / 2;
                    ++ map[value];
                }
            }
        }
        if (!map.empty()){
            max = std::max(std::prev(map.end()) -> first, max);
        }
        for (auto inter : vec2){
            auto w = set.find(inter);
            if (w == set.end() || !(*w == inter)){
                continue;
            }
            if (inter.type == 0){
                update(inter.l, inter.r, i);
            }
            else if (inter.type >= 2){
                if ((inter.r - inter.l) % 2 == 0){
                    if (inter.get_value(inter.l) == 1){
                        update(inter.l, inter.r, i);
                    }
                }
                else{
                    int mid = (inter.l + inter.r) / 2;
                    if (inter.get_value(inter.l) == 1){
                        update(inter.l, mid, i);
                    }
                    else{
                        update(mid + 1, inter.r, i);
                    }
                }
            }
        }
    }
    printf("%d\n", max);
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", c[ans[i]], " \n"[i == n]);
    }
    // printf("%.3f\n", 1.0 * (clock() - begin) / CLOCKS_PER_SEC);
    return 0;
}