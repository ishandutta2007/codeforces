#include<bits/stdc++.h>

const int N = 200010;

char s[N];
char ans[N];

int main(){
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    std::stack <int> stack;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '('){
            stack.push(i);
        }
        else{
            if (k == n){
                ans[stack.top()] = '(';
                ans[i] = ')';
            }
            else{
                k += 2;
            }
            stack.pop();
        }
    }
    for (int i = 0; i < n; ++ i){
        if (ans[i] != '\0'){
            putchar(ans[i]);
        }
    }
    putchar('\n');
    return 0;
}