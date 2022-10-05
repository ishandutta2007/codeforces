#include<bits/stdc++.h>

const int N = 30;

char s[N];
char ans[2][N];
int vis[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < n; ++ i){
        int &sit = vis[s[i] - 'A'];
        if (sit != -1){
            if (sit == i - 1){
                puts("Impossible");
                return 0;
            }
            int ul, dl;
            if (sit % 2 == i % 2){
                int num = (i - sit) / 2;
                ans[0][13 - num] = s[i];
                ul = dl = 12 - num;
                for (int j = sit + 1; j < sit + num; ++ j){
                    ans[0][13 - (j - sit)] = s[j];
                }
                std::reverse(ans[0] + 14 - num, ans[0] + 13);
                for (int j = sit + num; j < i; ++ j){
                    ans[1][12 - (j - sit - num)] = s[j];
                }
            }
            else{
                int num = (i - sit + 1) / 2;
                ans[0][13 - num] = s[i];
                ul = 12 - num;
                dl = ul + 1;
                for (int j = sit + 1; j < sit + num; ++ j){
                    ans[0][13 - (j - sit)] = s[j];
                }
                std::reverse(ans[0] + 14 - num, ans[0] + 13);
                for (int j = sit + num; j < i; ++ j){
                    ans[1][12 - (j - sit - num)] = s[j];
                }
            }
            bool flag = false;
            for (int j = sit - 1; j >= 0; -- j){
                if (ul < 0){
                    ul = 0, flag = true;
                }
                ans[flag][ul] = s[j];
                ul += flag ? 1 : -1;
            }
            flag = false;
            for (int j = i + 1; j < n; ++ j){
                if (dl < 0){
                    dl = 0, flag = true;
                }
                ans[!flag][dl] = s[j];
                dl += flag ? 1 : -1;
            }
        }
        else{
            sit = i;
        }
    }
    puts(ans[0]);
    puts(ans[1]);
}