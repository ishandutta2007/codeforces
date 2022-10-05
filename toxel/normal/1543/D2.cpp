#include <bits/stdc++.h>

const int N = 100;

int digit[N], digit1[N];

bool ask(int x){
    printf("%d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if (ret == -1){
        exit(0);
    }
    return ret;
}

void solve(){
    memset(digit, 0, sizeof(digit));
    int n, k;
    scanf("%d%d", &n, &k);
    int dcnt = 0, x = n - 1;
    while (x){
        x /= k;
        ++ dcnt;
    }
    dcnt = std::max(dcnt, 1);
    for (int i = 0; i < n; ++ i){
        x = i;
        for (int j = 0; j < dcnt; ++ j){
            digit1[j] = x % k;
            x /= k;
            if (i % 2 == 0){
                digit1[j] = (digit1[j] + digit[j]) % k;
            }
            else{
                digit1[j] = (-digit1[j] + digit[j] + k) % k;
            }
        }
        int sum = 0;
        for (int j = dcnt - 1; j >= 0; -- j){
            sum = sum * k + digit1[j];
        }
        if (ask(sum)){
            return;
        }
        for (int j = 0; j < dcnt; ++ j){
            digit[j] = (digit1[j] - digit[j] + k) % k;
        }
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}