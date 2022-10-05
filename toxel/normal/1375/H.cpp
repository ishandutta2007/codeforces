#include <bits/stdc++.h>

const int N = 10010;
const int BOUND = 16;
using pii = std::pair <int, int>;

struct Set{
    int id;
    int l, r;
};

std::map <pii, std::map <pii, Set>> map;
int map_id = 0;
int a[N];
std::vector<pii> set_print;

void insert(pii p1, pii p2, pii from){
    if (map.count(p1) && map[p1].count(p2)){
        return;
    }
    ++ map_id;
    map[p1][p2] = {map_id, from.first, from.second};
}

void merge(pii p1, pii p2, pii from){
    if (map.count(p1) && map[p1].count(p2)){
        return;
    }
    if (from.first && from.second){
        insert(p1, p2, from);
        set_print.emplace_back(from);
        return;
    }
    map[p1][p2] = {from.first ^ from.second, from.first, from.second};
}

Set query(pii value, int l, int r, bool strict=true){
    if (!strict){
        return map[value][{l, r}];
    }
    while (r >= l && !(value.first <= a[r] && a[r] <= value.second)){
        -- r;
    }
    if (r < l) return {0, 0, 0};
    while (!(value.first <= a[l] && a[l] <= value.second)){
        ++ l;
    }
    return map[value][{l, r}];
}

void merge(int vl, int vr, int n){
    if (vl == vr){
        return;
    }
    int mid = (vl + vr) / 2;
    merge(vl, mid, n);
    merge(mid + 1, vr, n);
    std::vector<int> pos;
    for (int i = 1; i <= n; ++ i){
        if (vl <= a[i] && a[i] <= vr){
            pos.emplace_back(i);
        }
    }
    int sz = pos.size();
    for (int i = 0; i < sz; ++ i){
        for (int j = i; j < sz; ++ j){
            Set setl = query({vl, mid}, pos[i], pos[j]);
            Set setr = query({mid + 1, vr}, pos[i], pos[j]);
            pii from = {setl.id, setr.id};
            merge({vl, vr}, {pos[i], pos[j]}, from);
        }
    }
}

int main(){
    std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
    int n, test;
    scanf("%d%d", &n, &test);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        insert({a[i], a[i]}, {i, i}, {0, 0});
    }
    if (n < BOUND){
        merge(1, n, n);
    }
    else{
        int mid = n / BOUND;
        for (int i = 0; i < BOUND; ++ i){
            merge(i * mid + 1, i == BOUND - 1 ? n : (i + 1) * mid, n);
        }
    }
    std::vector<int> ans(test);
    for (int i = 0; i < test; ++ i){
        int l, r;
        scanf("%d%d", &l, &r);
        if (n >= BOUND){
            int mid = n / BOUND;
            for (int j = 1; j < BOUND; ++ j){
                pii vl = {1, j * mid};
                pii vr = {j * mid + 1, j == BOUND - 1 ? n : (j + 1) * mid};
                Set setl = query(vl, l, r, j == 1);
                Set setr = query(vr, l, r, true);
                merge({vl.first, vr.second}, {l, r}, {setl.id, setr.id});
            }
        }
        ans[i] = query({1, n}, l, r, false).id;
    }
    printf("%d\n", map_id);
    for (auto p : set_print){
        printf("%d %d\n", p.first, p.second);
    }
    for (int i = 0; i < test; ++ i){
        printf("%d%c", ans[i], " \n"[i == test - 1]);
    }
    return 0;
}