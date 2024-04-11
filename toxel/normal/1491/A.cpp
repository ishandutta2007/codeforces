#include <bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        cnt0 += a[i] == 0;
        cnt1 += a[i] == 1;
    }
    while (q --){
        int type, x;
        scanf("%d%d", &type, &x);
        if (type == 1){
            if (a[x] == 0){
                ++ cnt1, -- cnt0;
            }
            else{
                ++ cnt0, -- cnt1;
            }
            a[x] ^= 1;
        }
        else{
            puts(cnt1 >= x ? "1" : "0");
        }
    }
    return 0;
}