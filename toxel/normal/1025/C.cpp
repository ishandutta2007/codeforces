#include<bits/stdc++.h>

const int N = 1000010;

char s[N];
int cnt[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = n; i < n << 1; ++ i){
        s[i] = s[i - n];
    }
    cnt[0] = 1;
    for (int i = 1; i < n << 1; ++ i){
        if (s[i] != s[i - 1]){
            cnt[i] = cnt[i - 1] + 1;
        }
        else{
            cnt[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n << 1; ++ i){
        ans = std::max(ans, cnt[i]);
    }
    printf("%d\n", std::min(ans, n));
    return 0;
}