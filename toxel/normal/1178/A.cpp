#include <bits/stdc++.h>

const int N = 110;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int now = a[0];
    std::vector <int> ans = {1};
    for (int i = 1; i < n; ++ i){
        if (a[0] >= 2 * a[i]){
            now += a[i];
            ans.push_back(i + 1);
        }
    }
    if (now * 2 > sum){
        int sz = ans.size();
        printf("%d\n", sz);
        for (int i = 0; i < sz; ++ i){
            printf("%d%c", ans[i], " \n"[i == sz - 1]);
        }
    } else{
        puts("0");
    }
    return 0;
}