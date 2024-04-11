#include <bits/stdc++.h>

const int N = 100010;

char s[N];

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (c == 0 && d == 0){
        if (std::abs(a - b) > 1){
            puts("NO");
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < std::min(a, b); ++ i){
            s[cnt ++] = '0';
            s[cnt ++] = '1';
        }
        std::string ans = s;
        if (a > b){
            ans = ans + "0";
        }
        else{
            ans = "1" + ans;
        }
        puts("YES");
        for (int i = 0; i < a + b + c + d; ++ i){
            printf("%c%c", ans[i], " \n"[i == a + b + c + d - 1]);
        }
        return 0;
    }
    if (a == 0 && b == 0){
        if (std::abs(c - d) > 1){
            puts("NO");
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < std::min(c, d); ++ i){
            s[cnt ++] = '2';
            s[cnt ++] = '3';
        }
        std::string ans = s;
        if (c > d){
            ans = ans + "2";
        }
        else{
            ans = "3" + ans;
        }
        puts("YES");
        for (int i = 0; i < a + b + c + d; ++ i){
            printf("%c%c", ans[i], " \n"[i == a + b + c + d - 1]);
        }
        return 0;
    }
    if (a > b || d > c) {
        puts("NO");
        return 0;
    }
    if (std::abs((b - a) - (c - d)) > 1) {
        puts("NO");
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < a; ++i) {
        s[cnt++] = '0';
        s[cnt++] = '1';
    }
    for (int i = 0; i < std::min(b - a, c - d); ++i) {
        s[cnt++] = '2';
        s[cnt++] = '1';
    }
    for (int i = 0; i < d; ++i) {
        s[cnt++] = '2';
        s[cnt++] = '3';
    }
    std::string ans = s;
    if (b - a > c - d){
        ans = "1" + ans;
    }
    else if (b - a < c - d){
        ans = ans + "2";
    }
    puts("YES");
    for (int i = 0; i < a + b + c + d; ++ i){
        printf("%c%c", ans[i], " \n"[i == a + b + c + d - 1]);
    }
    return 0;
}