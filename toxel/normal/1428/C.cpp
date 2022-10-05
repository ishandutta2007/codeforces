#include <bits/stdc++.h>

const int N = 200010;

char s[N];

void solve(){
    std::vector<char> stack;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++ i){
        if (!stack.empty() && s[i] == 'B'){
            stack.pop_back();
        }
        else{
            stack.push_back(s[i]);
        }
    }
    printf("%d\n", int(stack.size()));
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}