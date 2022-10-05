#include<bits/stdc++.h>

const int N = 1010;

int a[N], l[N], r[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &l[i]);
        if (l[i] > i){
            puts("NO");
            return 0;
        }
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &r[i]);
        if (r[i] > n - i - 1){
            puts("NO");
            return 0;
        }
        a[i] = n - l[i] - r[i];
    }
    for (int i = 0; i < n; ++ i){
        int cnt = 0;
        for (int j = 0; j < i; ++ j){
            if (a[j] > a[i]){
                ++ cnt;
            }
        }
        if (cnt != l[i]){
            puts("NO");
            return 0;
        }
        cnt = 0;
        for (int j = i + 1; j < n; ++ j){
            if (a[j] > a[i]){
                ++ cnt;
            }
        }
        if (cnt != r[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++ i){
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}