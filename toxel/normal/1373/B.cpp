#include <bits/stdc++.h>

const int N = 1010;

char s[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++ i){
        ++ (s[i] == '0' ? x : y);
        if (x && y){
            ++ z;
            -- x, -- y;
        }
    }
    puts(z & 1 ? "DA" : "NET");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}