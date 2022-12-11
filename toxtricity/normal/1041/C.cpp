#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
const int N = 200010;

int ans[N];

int main(){
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    std::set <pii> set;
    for (int i = 0, a; i < n; ++ i){
        scanf("%d", &a);
        set.insert({a, i});
    }
    int cnt = 0;
    while (!set.empty()){
        ++ cnt;
        int now = -m;
        std::vector <pii> vec;
        while (true){
            auto u = set.lower_bound({now + d + 1, INT_MIN});
            if (u == set.end()){
                break;
            }
            ans[u -> second] = cnt;
            vec.push_back(*u);
            now = u -> first;
        }
        for (auto u : vec){
            set.erase(u);
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
    return 0;
}