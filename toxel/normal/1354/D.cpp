#include <bits/stdc++.h>

const int MAX = 1 << 20;

int seg[MAX << 1];

void add(int sit, int value){
    seg[sit += MAX] += value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
    }
}

int query(int value){
    int sit = 1;
    for (int i = 0; i < 20; ++ i){
        if (seg[sit << 1] < value){
            value -= seg[sit << 1];
            sit = sit << 1 | 1;
        }
        else{
            sit = sit << 1;
        }
    }
    return sit - MAX;
}

void read(int &n){
    n = 0;
    bool flag = false;
    char ch;
    while (!isdigit(ch = getchar()) && ch != '-')
        ;
    if (ch == '-'){
        flag = true;
    }
    else{
        n = ch - '0';
    }
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
    if (flag){
         n = -n;
    }
}

int main(){
    int n, q;
    read(n), read(q);
    for (int i = 0; i < n; ++ i){
        int x;
        read(x);
        add(x, 1);
    }
    int cnt = n;
    while (q --){
        int t;
        read(t);
        if (t > 0){
            add(t, 1);
            ++ cnt;
        }
        else{
            int pos = query(-t);
            add(pos, -1);
            -- cnt;
        }
    }
    if (cnt == 0){
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        if (seg[i + MAX]){
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}