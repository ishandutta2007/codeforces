#include<bits/stdc++.h>

const int N = 100010;

char s[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    bool flag = true;
    for (int i = 0; i < n; ++ i){
        if (s[i] != 'a'){
            for (int j = i; j < n; ++ j){
                if (s[j] == 'a'){
                    break;
                }
                s[j] = s[j] - 1;
            }
            flag = false;
            break;
        }
    }
    if (flag){
        s[n - 1] = 'z';
    }
    puts(s);
    return 0;
}