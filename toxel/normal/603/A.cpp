#include<bits/stdc++.h>

const int N = 100010;

char s[N];

int main(){
    int n;
    scanf("%d%s", &n, s);
    int ans = 0, pre = 0;
    std::vector <int> vec;
    bool flag = false;
    for (int i = 0; i < n; ++ i){
        if (s[i] != s[i + 1]){
            if (i - pre + 1 >= 3 && !flag){
                ans += 2;
                flag = true;
            }
            ++ ans;
            vec.push_back(i - pre + 1);
            pre = i + 1;
        }
    }
    if (!flag){
        int cnt = 0;
        for (auto u : vec){
            cnt += u >= 2;
        }
        ans += std::min(cnt, 2);
    }
    printf("%d\n", ans);
    return 0;
}