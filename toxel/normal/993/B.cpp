#include<bits/stdc++.h>

const int N = 100;
typedef std::pair <int, int> pii;

pii a[N], b[N];
std::set <int> first[N], second[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, x, y; i < n; ++ i){
        scanf("%d%d", &x, &y);
        if (x > y) std::swap(x, y);
        a[i] = {x, y};
    }
    for (int i = 0, x, y; i < m; ++ i){
        scanf("%d%d", &x, &y);
        if (x > y) std::swap(x, y);
        b[i] = {x, y};
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (a[i] == b[j]) continue;
            if (a[i].first == b[j].first || a[i].first == b[j].second){
                first[i].insert(a[i].first);
            }
            if (a[i].second == b[j].first || a[i].second == b[j].second){
                first[i].insert(a[i].second);
            }
        }
    }
    for (int j = 0; j < m; ++ j){
        for (int i = 0; i < n; ++ i){
            if (a[i] == b[j]) continue;
            if (a[i].first == b[j].first || a[i].second == b[j].first){
                second[j].insert(b[j].first);
            }
            if (a[i].first == b[j].second || a[i].second == b[j].second){
                second[j].insert(b[j].second);
            }
        }
    }
    std::set <int> youfirst, yousecond;
    for (int i = 0; i < n; ++ i){
        for (auto u : first[i]){
            youfirst.insert(u);
        }
    }
    for (int i = 0; i < m; ++ i){
        for (auto u : second[i]){
            yousecond.insert(u);
        }
    }
    if (youfirst.size() == 1 && yousecond.size() == 1){
        printf("%d\n", *(youfirst.begin()));
        return 0;
    }
    bool flag = true;
    for (int i = 0; i < n; ++ i){
        if (first[i].size() > 1){
            flag = false;
            break;
        }
    }
    for (int i = 0; i < m; ++ i){
        if (second[i].size() > 1){
            flag = false;
            break;
        }
    }
    if (flag){
        puts("0");
        return 0;
    }
    puts("-1");
    return 0;
}