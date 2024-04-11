#include<bits/stdc++.h>

const int N = 1010;

char s[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    int now1 = 0, now2 = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '0'){
            printf("%d %d\n", 1, now1 + 1);
            now1 = (now1 + 1) % 4;
        }
        else{
            printf("%d %d\n", 3, now2 + 1);
            now2 = (now2 + 2) % 4;
        }
    }
    return 0;
}