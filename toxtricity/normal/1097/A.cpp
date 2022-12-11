#include<bits/stdc++.h>

char s[10];
char t[5][10];

int main(){
    scanf("%s", s);
    for (int i = 0; i < 5; ++ i){
        scanf("%s", t[i]);
    }
    for (int i = 0; i < 5; ++ i){
        if (s[0] == t[i][0] || s[1] == t[i][1]){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}