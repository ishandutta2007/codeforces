#include <bits/stdc++.h>

const int N = 300010;

char s[N];

void solve(){
    std::queue <char> odd, even;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++ i){
        (s[i] % 2 == 0 ? even : odd).push(s[i]);
    }
    while (!odd.empty() || !even.empty()){
        if (odd.empty() || (!even.empty() && even.front() < odd.front())){
            putchar(even.front());
            even.pop();
        }
        else{
            putchar(odd.front());
            odd.pop();
        }
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}