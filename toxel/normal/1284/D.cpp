#include <bits/stdc++.h>

struct Lecture{
    int sa, ea, sb, eb;
};

struct Event{
    int id, type;
};

const int N = 200010;

Lecture l[N];
int c[N];
std::vector <Event> vec[N];
int n;

void check(){
    for (int i = 0; i < N; ++ i){
        vec[i].clear();
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        c[cnt ++] = l[i].sa;
        c[cnt ++] = l[i].ea + 1;
    }
    std::sort(c, c + cnt);
    cnt = std::unique(c, c + cnt) - c;
    for (int i = 0; i < n; ++ i){
        int x = std::lower_bound(c, c + cnt, l[i].sa) - c;
        vec[x].push_back({i, 0});
        x = std::lower_bound(c, c + cnt, l[i].ea + 1) - c;
        vec[x].push_back({i, 1});
    }
    std::multiset <int> left, right;
    for (int i = 0; i < N; ++ i){
        for (auto u : vec[i]){
            if (u.type == 1){
                int id = u.id;
                auto v = left.find(l[id].sb);
                left.erase(v);
                v = right.find(l[id].eb);
                right.erase(v);
            }
        }
        for (auto u : vec[i]){
            if (u.type == 0){
                int id = u.id;
                if (!left.empty()){
                    if (l[id].sb > *(right.begin())){
                        puts("No");
                        exit(0);
                    }
                    if (l[id].eb < *std::prev(left.end())){
                        puts("No");
                        exit(0);
                    }
                }
                left.insert(l[id].sb);
                right.insert(l[id].eb);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d%d", &l[i].sa, &l[i].ea, &l[i].sb, &l[i].eb);
    }
    check();
    for (int i = 0; i < n; ++ i){
        std::swap(l[i].sa, l[i].sb);
        std::swap(l[i].ea, l[i].eb);
    }
    check();
    puts("Yes");
    return 0;
}