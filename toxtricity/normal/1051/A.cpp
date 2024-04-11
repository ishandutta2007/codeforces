#include<bits/stdc++.h>

const int N = 110;

char s[N];

void solve(){
    scanf("%s", s);
    int len = strlen(s);
    int low = 0, up = 0, digit = 0;
    for (int i = 0; i < len; ++ i){
        low += islower(s[i]) != 0;
        up += isupper(s[i]) != 0;
        digit += isdigit(s[i]) != 0;
    }
    if (low && up && digit){
        puts(s);
        return;
    }
    int cnt = (low > 0) + (up > 0) + (digit > 0);
    if (cnt == 2){
        if (low > 1){
            for (int i = 0; i < len; ++ i){
                if (islower(s[i])){
                    s[i] = up ? '0' : 'A';
                    break;
                }
            }
        }
        else if (up > 1){
            for (int i = 0; i < len; ++ i){
                if (isupper(s[i])){
                    s[i] = low ? '0' : 'a';
                    break;
                }
            }
        }
        else{
            for (int i = 0; i < len; ++ i){
                if (isdigit(s[i])){
                    s[i] = up ? 'a' : 'A';
                    break;
                }
            }
        }
    }
    else{
        if (low){
            s[0] = 'A';
            s[1] = '0';
        }
        else if (up){
            s[0] = 'a';
            s[1] = '0';
        }
        else{
            s[0] = 'a';
            s[1] = 'A';
        }
    }
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