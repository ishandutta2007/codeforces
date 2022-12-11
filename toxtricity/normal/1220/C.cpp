#include <bits/stdc++.h>

const int N = 500010;

bool vis[N];
char s[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++ i){
        bool flag = false;
        for (int j = 0; j < s[i] - 'a'; ++ j){
            if (vis[j]){
                flag = true;
                break;
            }
        }
        puts(flag ? "Ann" : "Mike");
        vis[s[i] - 'a'] = true;
    }
    return 0;
}