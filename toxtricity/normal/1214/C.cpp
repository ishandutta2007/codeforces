#include <bits/stdc++.h>

const int N = 200010;

char s[N];
int pre[N];

int main(){
    int n;
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
    }
    if (pre[n]){
        puts("No");
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        if (pre[i] < -1){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}