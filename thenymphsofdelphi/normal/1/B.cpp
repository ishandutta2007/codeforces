#include<bits/stdc++.h>
using namespace std;

void f(int t){
    if (t){
        f((t - 1) / 26);
        putchar(65 + (t - 1) % 26);
    }
}

int main(){
    int n, x, y;
    char s[64], *p;
    for (scanf("%d ",&n); n--;){
        gets(s);
        if (sscanf(s,"%*c%d%*c%d", &x, &y) == 2){
            f(y);
            printf("%d\n", x);
        }
        else{
            for (x = 0, p = s; *p > 64; p++){
                x = x * 26 + *p - 64;
            }
            printf("R%sC%d\n", p, x);
        }
    }
    return 0;
}