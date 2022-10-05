#include <bits/stdc++.h>

const int N = 100010;

int a[N], pre[N], suf[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n; i >= 1; -- i){
        suf[i] = suf[i + 1] | a[i];
    }
    int max = -1, pos = 0;
    for (int i = 1; i <= n; ++ i){
        int sub = pre[i - 1] | suf[i + 1];
        int x = a[i] ^ (a[i] & sub);
        if (x > max){
            max = x;
            pos = i;
        }
    }
    printf("%d", a[pos]);
    for (int i = 1; i <= n; ++ i){
        if (i != pos){
            printf(" %d", a[i]);
        }
    }
    puts("");
    return 0;
}