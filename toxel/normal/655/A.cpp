#include<bits/stdc++.h>

char s[10][10], t[10][10];

int main(){
    scanf("%s%s%s%s", s[0], s[1], t[0], t[1]);
    char tmp1[] = {s[0][0], s[0][1], s[1][1], s[1][0]};
    char tmp2[] = {t[0][0], t[0][1], t[1][1], t[1][0]};
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 4; ++ i){
        for (int j = i + 1; j < 4; ++ j){
            if (tmp1[i] != 'X' && tmp1[j] != 'X' && tmp1[i] > tmp1[j]){
                ++ cnt1;
            }
            if (tmp2[i] != 'X' && tmp2[j] != 'X' && tmp2[i] > tmp2[j]){
                ++ cnt2;
            }
        }
    }
    puts(cnt1 % 2 == cnt2 % 2 ? "YES" : "NO");
    return 0;
}