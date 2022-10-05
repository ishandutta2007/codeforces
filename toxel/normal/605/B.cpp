#include<bits/stdc++.h>

const int N = 100010;
typedef std::pair <int, int> pii;

std::pair <pii, int> p[N];
pii ans[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; ++ i){
        scanf("%d%d", &a, &b);
        p[i] = {{a, -b}, i};
    }
    std::sort(p, p + m);
    std::set <pii> set;
    int nown = 0;
    for (int i = 0; i < m; ++ i){
        if (!p[i].first.second){
            if (set.empty()){
                puts("-1");
                return 0;
            }
            auto u = set.begin();
            ans[p[i].second] = *u;
            set.erase(u);
            continue;
        }
        if (!nown){
            nown += 2;
            ans[p[i].second] = {1, 2};
        }
        else{
            ++ nown;
            ans[p[i].second] = {1, nown};
            for (int i = 2; i < nown && set.size() < N; ++ i){
                set.insert({i, nown});
            }
        }
    }
    for (int i = 0; i < m; ++ i){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}