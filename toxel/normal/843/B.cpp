#include<bits/stdc++.h>

const int N = 50010;
const int THRE = 1010;

int a[N], next[N]; 

void query(int sit){
    printf("? %d\n", sit + 1);
    fflush(stdout);
    scanf("%d%d", &a[sit], &next[sit]);
    if (next[sit] > 0){
        -- next[sit];
    }
}

int randint(int n){
    return (1ll * rand() << 15 | rand()) % n;
}

int main(){
    srand((unsigned) time(NULL));
    int n, start, x;
    scanf("%d%d%d", &n, &start, &x);
    -- start;
    int max = 0;
    for (int i = 0; i < THRE; ++ i){
        int sit = randint(n);
        query(sit);
        if (a[sit] < x && a[sit] > max){
            start = sit;
            max = a[sit];
        }
    }
    while (start != -1){
        query(start);
        if (a[start] >= x){
            printf("! %d\n", a[start]);
            return 0;
        }
        start = next[start];
    }
    puts("! -1");
    return 0;
}