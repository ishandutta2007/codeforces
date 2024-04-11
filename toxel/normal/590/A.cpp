#include<bits/stdc++.h>

const int N = 500010;

int a[N];
bool flag[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n - 1; ++ i){
        flag[i] = a[i] != a[i - 1] && a[i] != a[i + 1];
    }
    int pre = 0, max = 0;
    for (int i = 1; i < n; ++ i){
        if (flag[i]){
            if (!pre){
                pre = i;
            }
        }
        else{
            if (!pre) continue;
            max = std::max(max, i - pre + 1 >> 1);
            if (i - pre & 1){
                for (int j = pre; j < i; ++ j){
                    a[j] = a[pre - 1];
                }
            }
            else{
                int mid = pre + i >> 1;
                for (int j = pre; j < mid; ++ j){
                    a[j] = a[pre - 1];
                }
                for (int j = mid; j < i; ++ j){
                    a[j] = a[i];
                }
            }
            pre = 0;
        }
    }
    printf("%d\n", max);
    for (int i = 0; i < n; ++ i){
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}