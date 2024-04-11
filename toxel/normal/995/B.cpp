#include<bits/stdc++.h>

const int N = 210;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n << 1; ++ i){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n << 1; i += 2){
        int sit;
        for (int j = i + 1; j < n << 1; ++ j){
            if (a[i] == a[j]){
                sit = j;
                break;
            }
        }
        ans += sit - i - 1;
        for (int j = sit; j > i; -- j){
            a[j] = a[j - 1];
        }
    }
    printf("%d\n", ans);
    return 0;
}