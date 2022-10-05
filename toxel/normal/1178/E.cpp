#include <bits/stdc++.h>

const int N = 1000010;

char s[N];
bool vis[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    int l = 0, r = n - 1;
    while (true){
        if (r < l){
            break;
        }
        if (l >= r - 2){
            vis[l] = true;
            break;
        }
        if (s[l] == s[r]){
            vis[l] = vis[r] = true;
        }
        else if (s[l] == s[r - 1]){
            vis[l] = vis[r - 1] = true;
        }
        else if (s[l + 1] == s[r]){
            vis[l + 1] = vis[r] = true;
        }
        else if (s[l + 1] == s[r - 1]){
            vis[l + 1] = vis[r - 1] = true;
        }
        l += 2, r -= 2;
    }
    for (int i = 0; i < n; ++ i){
        if (vis[i]){
            putchar(s[i]);
        }
    }
    puts("");
    return 0;
}