#include<bits/stdc++.h>

bool check(char ch){
    char s[] = "aeiou";
    for (int i = 0; i < 5; ++ i){
        if (s[i] == ch){
            return true;
        }
    }
    return false;
}

const int N = 1010;

char s[N], t[N];

int main(){
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    if (n != m){
        puts("No");
        return 0;
    }
    for (int i = 0; i < n; ++ i){
        if (check(s[i]) != check(t[i])){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}