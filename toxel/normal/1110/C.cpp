#include<bits/stdc++.h>

const int N = 26;

int ans[N] = {0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int main(){
    /*for (int i = 2; i < N; ++ i){
        int x = (1 << i) - 1;
        for (int j = 1; j + j <= x; ++ j){
            ans[i] = std::max(ans[i], std::__gcd(j, x - j));
        }
    }
    for (int i = 0; i < N; ++ i){
        printf("%d,", ans[i]);
    }*/
    int test;
    scanf("%d", &test);
    while (test --){
        int a;
        scanf("%d", &a);
        int cnt = 0, x = a;
        bool flag = true;
        while (x){
            ++ cnt;
            if ((x & 1) == 0){
                flag = false;
            }
            x >>= 1;
        }
        if (flag){
            printf("%d\n", ans[cnt]);
        }
        else{
            printf("%d\n", (1 << cnt) - 1);
        }
    }
    return 0;
}