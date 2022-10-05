#include<bits/stdc++.h>

int ask(int l, int r){
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int t;
    scanf("%d", &t);
    if (t == -1){
        exit(0);
    }
    return t;
}

const int N = 310;

int a[N], rev[N];

bool check(int l, int r, int diff){
    return ((r - l + 1 + diff) & 1) == 0;
}

void rever(int l, int r){
    for (int i = l; i <= r; ++ i){
        rev[i] ^= 1;
    }
}

int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    if (n == 1){
        printf("! %d\n", t);
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        if (i == 1){
            while (true){
                int nt = ask(2, n);
                if (check(2, n, nt - t)){
                    rever(2, n);
                    a[1] = rev[1] ^ (n - t + 1 == nt);
                    t = nt;
                    break;
                }
                else{
                    rever(1, n);
                    t = nt;
                }
            }
            continue;
        }
        int r = i, l = ((n - 1) & 1) == ((r - 1) & 1) ? 2 : 1;
        while (true){
            int nt = ask(l, r);
            if (check(1, r, nt - t)){
                int cnt = 0;
                for (int j = 1; j <= i; ++ j){
                    cnt += a[j] ^ rev[j];
                }
                if (i - cnt + t - cnt != nt){
                    a[i] = 1;
                }
                rever(1, r);
                t = nt;
                break;
            }
            else{
                rever(l, n);
                t = nt;
            }
        }
    }
    printf("! ");
    for (int i = 1; i <= n; ++ i){
        putchar('0' + a[i]);
    }
    putchar('\n');
    return 0;
}