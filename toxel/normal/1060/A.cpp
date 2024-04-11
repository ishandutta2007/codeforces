#include<bits/stdc++.h>

const int N = 110;

char s[N];

int main(){
    int n;
    scanf("%d%s", &n, s);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        cnt += s[i] == '8';
    }
    printf("%d\n", std::min(cnt, n / 11));
    return 0;
}