#include<bits/stdc++.h>

const int N = 10;

int a[N];
char s[N];

int main(){
    for (int i = 0; i < N; ++ i){
        a[i] = 2;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++ i){
        scanf("%s%d", s, &x);
        for (int j = 0; j < N; ++ j){
            if (s[0] == '&'){
                if (!(x >> j & 1)){
                    a[j] = 0;
                }
            }
            else if (s[0] == '|'){
                if (x >> j & 1){
                    a[j] = 1;
                }
            }
            else{
                a[j] ^= x >> j & 1;
            }
        }
    }
    int ansand = 0x3ff, ansor = 0, ansxor = 0;
    for (int i = 0; i < N; ++ i){
        if (a[i] == 0){
            ansand ^= 1 << i;
        }
        else if (a[i] == 1){
            ansor ^= 1 << i;
        }
        else if (a[i] == 3){
            ansxor ^= 1 << i;
        }
    }
    puts("3");
    printf("& %d\n| %d\n^ %d\n", ansand, ansor, ansxor);
    return 0;
}