#include<bits/stdc++.h> 

const int N = 30;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int max = 0, sit;
    for (int i = 1; i <= 100000; ++ i){
        bool div = true;
        for (int j = 0; j < n; ++ j){
            if (a[j] % i){
                div = false;
                break;
            }
        }
        if (!div) continue;
        int oddcnt = 0;
        for (int j = 0; j < n; ++ j){
            oddcnt += a[j] / i & 1;
        }
        if (oddcnt > 1) continue;
        int value = i * (oddcnt ? 1 : 2);
        if (max < value){
            max = value;
            sit = i;
        }
    }
    printf("%d\n", max);
    if (!max){
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < a[i]; ++ j){
                putchar('a' + i);
            }
        }
        putchar('\n');
        return 0;
    }
    for (int i = 0; i < n; ++ i){
        a[i] /= sit;
    }
    for (int times = 0; times < sit; ++ times){
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < a[i] >> 1; ++ j){
                putchar('a' + i);
            }
        }
        for (int i = 0; i < n; ++ i){
            if (a[i] & 1){
                putchar('a' + i);
            }
        }
        for (int i = n - 1; i >= 0; -- i){
            for (int j = 0; j < a[i] >> 1; ++ j){
                putchar('a' + i);
            }
        }
    }
    putchar('\n');
    return 0;
}