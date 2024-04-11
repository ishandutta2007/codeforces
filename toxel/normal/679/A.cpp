#include<bits/stdc++.h>

const int N = 100;

char s[N];

bool query(int n){
    printf("%d\n", n);
    fflush(stdout);
    scanf("%s", s);
    return !strcmp(s, "yes");
}

int main(){
    bool div2 = query(2);
    bool div3 = query(3);
    bool div5 = query(5);
    bool div7 = query(7);
    if (!div2 && !div3 && !div5 && !div7){
        puts("prime");
        return 0;
    }
    if (div2 + div3 + div5 + div7 > 1){
        puts("composite");
        return 0;
    }
    if (query(4) || query(9) || query(25) || query(49)){
        puts("composite");
        return 0;
    }
    for (int i = 11; i <= 50; ++ i){
        bool flag = true;
        for (int j = 2; j * j <= i; ++ j){
            if (i % j == 0){
                flag = false;
                break;
            }
        }
        if (flag && query(i)){
            puts("composite");
            return 0;
        }
    }
    puts("prime");
    return 0;
}