#include <bits/stdc++.h>

const int N = 100010;

char s[N];

void solve(){
    int n;
    scanf("%d%s", &n, s);
    std::sort(s, s + n);
    puts(s);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}