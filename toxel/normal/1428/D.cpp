#include <bits/stdc++.h>

const int N = 100010;

int a[N];
std::vector<int> ans[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::vector<int> one, two, three;
    int cur = 0;
    for (int i = n - 1; i >= 0; -- i){
        if (a[i] == 0){
            continue;
        }
        if (a[i] == 1){
            ++ cur;
            ans[i].emplace_back(cur);
            one.emplace_back(i);
            continue;
        }
        if (a[i] == 2){
            if (one.empty()){
                puts("-1");
                return 0;
            }
            int pos = one.back();
            one.pop_back();
            ans[i].emplace_back(ans[pos][0]);
            two.emplace_back(i);
            continue;
        }
        if (a[i] == 3){
            if (!three.empty()){
                int pos = three.back();
                three.pop_back();
                ++ cur;
                ans[i].emplace_back(cur);
                ans[pos].emplace_back(cur);
                three.emplace_back(i);
                continue;
            }
            if (!two.empty()){
                int pos = two.back();
                two.pop_back();
                ++ cur;
                ans[i].emplace_back(cur);
                ans[pos].emplace_back(cur);
                three.emplace_back(i);
                continue;
            }
            if (!one.empty()){
                int pos = one.back();
                one.pop_back();
                ++ cur;
                ans[i].emplace_back(cur);
                ans[pos].emplace_back(cur);
                three.emplace_back(i);
                continue;
            }
            puts("-1");
            return 0;
        }
    }
    int sum = 0;
    for (const auto &u : ans){
        sum += u.size();
    }
    printf("%d\n", sum);
    for (int i = 0; i < n; ++ i){
        for (auto v : ans[i]){
            printf("%d %d\n", n + 1 - v, i + 1);
        }
    }
    return 0;
}