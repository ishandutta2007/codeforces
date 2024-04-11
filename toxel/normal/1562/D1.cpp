#include <bits/stdc++.h>

const int N = 300010;

char s[N];
int pre[N], pre1[N];

void solve(){
    int n, test;
    scanf("%d%d", &n, &test);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++ i){
        if (i % 2 == 1){
            s[i] = s[i] == '+' ? '-' : '+';
        }
    }
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (s[i] == '+');
        pre1[i] = pre1[i - 1] + (s[i] == '-');
    }
    while (test --){
        int l, r;
        scanf("%d%d", &l, &r);
        int x = pre[r] - pre[l - 1];
        int x1 = pre1[r] - pre1[l - 1];
        if (x == x1){
            puts("0");
            continue;
        }
        if ((r - l + 1) % 2 == 1){
            puts("1");
        }
        else{
            puts("2");
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