#include <bits/stdc++.h>

const int N = 2010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int ans = n;
    std::set <int> set;
    for (int i = 0; i <= n - 1; ++ i){
        std::set <int> tmpset = set;
        ans = std::min(ans, n - i);
        for (int j = n - 1; j >= i; -- j){
            if (tmpset.count(a[j])){
                break;
            }
            tmpset.insert(a[j]);
            ans = std::min(ans, j - i);
        }
        if (set.count(a[i])){
            break;
        }
        set.insert(a[i]);
    }
    printf("%d\n", ans);
    return 0;
}