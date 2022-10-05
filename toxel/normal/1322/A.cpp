#include <bits/stdc++.h>

const int N = 1000010;

char s[N];
int pre[N];

int main(){
    int n;
    scanf("%d%s", &n, s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
    }
    if (pre[n] != 0){
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        cnt += pre[i] < 0 || (pre[i] == 0 && pre[i - 1] < 0);
    }
    printf("%d\n", cnt);
    return 0;
}