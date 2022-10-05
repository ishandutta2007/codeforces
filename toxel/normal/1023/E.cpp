#include<bits/stdc++.h>

const int N = 10010;

char s[10];
char ans[N];
int n;

bool ask(int x1, int y1, int x2, int y2){
    if (x1 < 0 || y1 >= n || x2 < 0 || y2 >= n) return false;
    printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
    fflush(stdout);
    scanf("%s", s);
    return !strcmp(s, "YES");
}

int main(){
    scanf("%d", &n);
    std::vector <char> ans1, ans2;
    int nowx = 0, nowy = 0;
    for (int i = 0; i < n - 1; ++ i){
        if (ask(nowx + 1, nowy, n - 1, n - 1)){
            ans1.push_back('D');
            ++ nowx;
        }
        else{
            ans1.push_back('R');
            ++ nowy;
        }
    }
    nowx = n - 1, nowy = n - 1;
    for (int i = 0; i < n - 1; ++ i){
        if (ask(0, 0, nowx, nowy - 1)){
            ans2.push_back('R');
            -- nowy;
        }
        else{
            ans2.push_back('D');
            -- nowx;
        } 
    }
    std::reverse(ans2.begin(), ans2.end());
    printf("! ");
    for (auto u : ans1){
        putchar(u);
    }
    for (auto u : ans2){
        putchar(u);
    }
    putchar('\n');
    return 0;
}