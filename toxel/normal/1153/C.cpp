#include <bits/stdc++.h>

const int N = 300010;

char s[N];

int main(){
    int n;
    scanf("%d%s", &n, s);
    if (n & 1){
        puts(":(");
        return 0;
    }
    int l = 0, r = 0, no = 0;
    for (int i = 0; i < n; ++ i){
        l += s[i] == '(';
        r += s[i] == ')';
        no += s[i] == '?';
    }
    int x = (r - l + no) / 2;
    if (x < 0 || x > no){
        puts(":(");
        return 0;
    }
    int y = no - x;
    for (int i = 0; i < n; ++ i){
        if (s[i] != '?'){
            continue;
        }
        if (x){
            s[i] = '(';
            -- x;
        }
        else{
            s[i] = ')';
            -- y;
        }
    }
    bool flag = true;
    int now = 0;
    for (int i = 0; i < n; ++ i){
        now += s[i] == '(' ? 1 : -1;
        if (i < n - 1 && !now){
            flag = false;
            break;
        }
        if (now < 0){
            flag = false;
            break;
        }
    }
    if (flag){
        puts(s);
    }
    else{
        puts(":(");
    }
    return 0;
}