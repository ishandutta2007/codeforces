#include <bits/stdc++.h>

const int N = 400010;
const int BIT = 25;

int a[N], b[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int base = 0;
    if (n % 2 == 0){
        for (int i = 0; i < n; ++ i){
            base ^= a[i];
        }
    }
    for (int i = 0; i < BIT; ++ i){
        for (int j = 0; j < n; ++ j){
            b[j] = a[j] & ((1 << (i + 1)) - 1);
        }
        std::sort(b, b + n);
        int tot = 0;
        for (int j = 0, k = n - 1; j < n; ++ j){
            while (k >= 0 && b[j] + b[k] >= (1 << (i + 1))){
                -- k;
            }
            if (k <= j){
                tot ^= n - 1 - j;
            }
            else{
                tot ^= n - 1 - k;
            }
        }
        tot &= 1;
        base ^= tot << (i + 1);
    }
    printf("%d\n", base);
    /*int ans = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            ans ^= a[i] + a[j];
        }
    }
    printf("%d\n", ans);*/
    return 0;
}