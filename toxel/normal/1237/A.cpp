#include <bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (a[i] & 1){
            ++ cnt;
            if (cnt & 1){
                a[i] = a[i] >> 1;
            }
            else{
                a[i] = (a[i] >> 1) + 1;
            }
        }
        else{
            a[i] >>= 1;
        }
        printf("%d\n", a[i]);
    }
    return 0;
}