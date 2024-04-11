#include <bits/stdc++.h>

const int N = 100;

int a[N];

void perform(std::vector<int> vec, int n){
    std::vector<int> na;
    int sz = vec.size();
    int nn = n;
    for (int i = sz - 1; i >= 0; -- i){
        for (int j = nn - vec[i]; j < nn; ++ j){
            na.emplace_back(a[j + 1]);
        }
        nn -= vec[i];
    }
    for (int i = 0; i < n; ++ i){
        a[i + 1] = na[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    std::vector<std::vector<int>> ans;
    for (int i = 2; i <= n; ++ i){
        int pos = 0, end = 0;
        for (int j = 1; j <= n; ++ j){
            if (a[j] < i){
                end = j;
            }
            if (a[j] == i){
                pos = j;
            }
        }
        int begin = end - i + 2;
        std::set <int> set;
        if (begin < pos){
            if (a[begin] < a[end]){
                set.insert(begin - 1);
                for (int j = begin; j <= end; ++ j){
                    set.insert(j);
                }
                set.insert(pos);
            }
            else{
                set.insert(begin - 1);
                set.insert(pos - 1);
                set.insert(pos);
            }
        }
        else{
            if (a[begin] > a[end]){
                set.insert(pos - 1);
                set.insert(begin - 1);
                for (int j = begin; j <= end; ++ j){
                    set.insert(j);
                }
            }
            else{
                set.insert(pos - 1);
                set.insert(pos);
                set.insert(end);
            }
        }
        set.insert(0);
        set.insert(n);
        std::vector<int> vec;
        int pre = 0;
        for (auto u : set){
            if (u){
                vec.emplace_back(u - pre);
                pre = u;
            }
        }
        ans.emplace_back(vec);
        perform(vec, n);
    }
    if (a[1] != 1){
        std::vector<int> vec(n, 1);
        ans.emplace_back(vec);
        perform(vec, n);
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (auto u : ans){
        printf("%d", int(u.size()));
        for (auto v : u){
            printf(" %d", v);
        }
        puts("");
    }
    /*for (int i = 1; i <= n; ++ i){
        printf("%d\n", a[i]);
    }*/
    return 0;
}