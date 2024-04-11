#include <bits/stdc++.h>

const int N = 100010;

int a[N], ans[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::set <int> appear, notappear;
    for (int i = 0; i < n; ++ i){
        appear.insert(a[i]);
    }
    for (int i = 0; i < 300'000; ++ i){
        if (!appear.count(i)){
            notappear.insert(i);
        }
    }
    if (a[0] == 0){
        ans[0] = -1;
        for (int i = 1; i < n; ++ i){
            if (a[i] == i + 1){
                ans[0] = i;
                break;
            }
        }
        if (ans[0] == -1){
            ans[0] = 300'000;
        }
    }
    else{
        ans[0] = 0;
    }
    notappear.erase(ans[0]);
    for (int i = 0, j = 0; i < n; i = j){
        while (j < n && a[i] == a[j]){
            ++ j;
        }
        for (int k = i + 1; k < j; ++ k){
            auto u = notappear.begin();
            ans[k] = *u;
            notappear.erase(u);
        }
        if (j < n){
            ans[j] = a[i];
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
}