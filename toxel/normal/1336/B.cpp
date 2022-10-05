#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

ll sqr(int x){return 1ll * x * x;}

ll sum(int a, int b, int c){return sqr(a - b) + sqr(b - c) + sqr(a - c);}

ll calc(std::vector <int> &vec1, std::vector<int> &vec2, std::vector<int>&vec3){
    ll min = LLONG_MAX;
    int n = vec1.size();
    for (int i = 0; i < n; ++ i){
        auto v = std::lower_bound(vec3.begin(), vec3.end(), vec1[i]);
        if (v == vec3.end()){
            continue;
        }
        int mid = (vec1[i] + *v) / 2;
        auto check = [&](int pos){
            if (pos < 0 || pos >= int(vec2.size())){
                return;
            }
            min = std::min(min, sum(vec1[i], *v, vec2[pos]));
        };
        int pos = std::lower_bound(vec2.begin(), vec2.end(), mid) - vec2.begin();
        for (int i = pos - 2; i <= pos + 2; ++ i){
            check(i);
        }
    }
    return min;
}

void solve(){
    int n1, n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);
    std::vector <int> vec1(n1), vec2(n2), vec3(n3);
    for (int i = 0; i < n1; ++ i){
        scanf("%d", &vec1[i]);
    }
    for (int i = 0; i < n2; ++ i){
        scanf("%d", &vec2[i]);
    }
    for (int i = 0; i < n3; ++ i){
        scanf("%d", &vec3[i]);
    }
    auto erase = [](std::vector <int> &vec){
        std::sort(vec.begin(), vec.end());
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    };
    erase(vec1);
    erase(vec2);
    erase(vec3);
    ll min = LLONG_MAX;
    min = std::min(min, calc(vec1, vec2, vec3));
    min = std::min(min, calc(vec1, vec3, vec2));
    min = std::min(min, calc(vec2, vec1, vec3));
    min = std::min(min, calc(vec2, vec3, vec1));
    min = std::min(min, calc(vec3, vec1, vec2));
    min = std::min(min, calc(vec3, vec2, vec1));
    printf("%lld\n", min);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}