#include<bits/stdc++.h>

const int N = 200010;

char s[N], t[N];

int main(){
    int n, m;
    scanf("%d%d%s%s", &n, &m, s, t);
    int sit = -1;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '*'){
            sit = i;
            break;
        }
    }
    if (sit == -1){
        puts(!strcmp(s, t) ? "YES" : "NO");
        return 0;
    }
    for (int i = 0; i < sit; ++ i){
        if (s[i] != t[i]){
            puts("NO");
            return 0;
        }
    }
    if (n > m + 1){
        puts("NO");
        return 0;
    }
    for (int i = n - 1; i > sit; -- i){
        if (s[i] != t[i - n + m]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}