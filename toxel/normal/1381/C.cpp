#include <bits/stdc++.h>

const int N = 100010;
using pii = std::pair <int, int>;

std::vector<int> vec[N];
int a[N], b[N];

void solve(){
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i <= n + 1; ++ i){
        vec[i].clear();
    }
    memset(a, 0, sizeof(a[0]) * (n + 1));
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
        vec[b[i]].emplace_back(i);
    }
    if (x > y){
        puts("NO");
        return;
    }
    int no = 0;
    int nn = n;
    std::set <pii> set;
    for (int i = 1; i <= n + 1; ++ i){
        set.insert({vec[i].size(), i});
        if (vec[i].empty()){
            no = i;
        }
    }
    while (x > 0){
        auto u = std::prev(set.end());
        int pos = u -> second;
        set.erase(u);
        int sit = vec[pos].back();
        a[sit] = b[sit];
        vec[pos].pop_back();
        set.insert({vec[pos].size(), pos});
        -- n, -- x, -- y;
    }
    while (n > y){
        auto u = std::prev(set.end());
        int pos = u -> second;
        set.erase(u);
        int sit = vec[pos].back();
        a[sit] = no;
        vec[pos].pop_back();
        set.insert({vec[pos].size(), pos});
        -- n;
    }
    int num = std::prev(set.end()) -> first;
    std::vector<int> pos;
    for (int i = 1; i <= nn; ++ i){
        if (!a[i]){
            pos.emplace_back(i);
        }
    }
    std::sort(pos.begin(), pos.end(), [&](const int &p1, const int &p2){return b[p1] < b[p2];});
    for (int i = 0, sz = pos.size(); i < sz; ++ i){
        int xx = pos[i], yy = pos[(i + num) % sz];
        a[xx] = b[yy];
    }
    int same = 0;
    for (auto u : pos){
        same += a[u] == b[u];
    }
    if (same > 1){
        puts("NO");
        return;
    }
    if (same == 1){
        int pos1 = 0, pos2 = 0;
        for (auto i : pos){
            if (a[i] == b[i]){
                pos1 = i;
            }
        }
        for (int i = 1; i <= nn; ++ i){
            if (a[i] == no && b[i] != b[pos1]){
                pos2 = i;
            }
        }
        if (pos2 == 0){
            puts("NO");
            return;
        }
        std::swap(a[pos1], a[pos2]);
    }
    puts("YES");
    for (int i = 1; i <= nn; ++ i){
        printf("%d%c", a[i], " \n"[i == nn]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}