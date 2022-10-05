#include<bits/stdc++.h>

const int N = 100010;

char s[N];
int cnt[N];

int main(){
    int n;
    scanf("%d%s", &n, s);
    if (n == 1){
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < n; ++ i){
        ++ cnt[s[i]];
    }
    for (int i = 0; i < N; ++ i){
        if (cnt[i] >= 2){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}