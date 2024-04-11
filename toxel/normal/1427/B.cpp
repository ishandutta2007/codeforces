#include <bits/stdc++.h>

const int N = 100010;

char s[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == 'W'){
            ++ ans;
            if (i && s[i] == s[i - 1]){
                ++ ans;
            }
        }
    }
    std::vector<int> vec;
    int begin = 0, back = 0;
    int pre = -1;
    for (int i = 0; i < n; ++ i){
        if (i == n - 1 || s[i] != s[i + 1]){
            if (s[i] == 'L'){
                vec.emplace_back(i - pre);
            }
            pre = i;
        }
    }
    if (s[0] == 'L'){
        begin = vec.front();
        vec.erase(vec.begin());
    }
    if (begin == n){
        printf("%d\n", k == 0 ? 0 : 2 * k - 1);
        return;
    }
    if (s[n - 1] == 'L'){
        back = vec.back();
        vec.pop_back();
    }
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    while (k > 0 && !vec.empty()){
        if (vec.back() == 1){
            ans += 3;
        }
        else{
            ans += 2;
        }
        -- k;
        -- vec.back();
        if (!vec.back()){
            vec.pop_back();
        }
    }
    while (k > 0 && back){
        ans += 2;
        -- k;
        -- back;
    }
    while (k > 0 && begin){
        ans += 2;
        -- k;
        -- begin;
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}