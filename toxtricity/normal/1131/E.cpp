#include <bits/stdc++.h>

const int N = 100010;
const int INF = 1e9;

int dp[N];
char s[N];

int mult(int a, int b){
    if (!a || !b) return 0;
    return INF / a >= b ? a * b : INF;
}

int add(int a, int b){
    return std::min(a + b, INF);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s);
        int len = strlen(s);
        bool flag = true;
        for (int j = 1; j < len; ++ j){
            if (s[j] != s[0]){
                flag = false;
                break;
            }
        }
        if (flag){
            int sit = s[0] - 'a';
            dp[sit] = add(dp[sit], mult(dp[sit] + 1, len));
            for (int j = 0; j < 26; ++ j){
                if (j != sit){
                    dp[j] = std::min(dp[j], 1);
                }
            }
        }
        else{
            int begin, end;
            for (int j = 1; j < len; ++ j){
                if (s[j] != s[0]){
                    begin = j;
                    break;
                }
            }
            for (int j = len - 2; j >= 0; -- j){
                if (s[j] != s[len - 1]){
                    end = j;
                    break;
                }
            }
            if (s[0] == s[len - 1]){
                int sit = s[0] - 'a';
                if (dp[sit]){
                    dp[sit] = std::min(dp[sit], 1) + begin + len - 1 - end;
                }
                else{
                    dp[sit] = std::max(begin, len - 1 - end);
                }
                for (int j = 0; j < 26; ++ j){
                    if (j != sit){
                        dp[j] = std::min(dp[j], 1);
                    }
                }
            }
            else{
                int sit1 = s[0] - 'a', sit2 = s[len - 1] - 'a';
                dp[sit1] = std::min(dp[sit1], 1) + begin;
                dp[sit2] = std::min(dp[sit2], 1) + len - 1 - end;
                for (int j = 0; j < 26; ++ j){
                    if (j != sit1 && j != sit2){
                        dp[j] = std::min(dp[j], 1);
                    }
                }
            }
            int pre = begin;
            for (int j = begin; j <= end + 1; ++ j){
                if (j == end + 1 || (j > begin && s[j] != s[j - 1])){
                    int &u = dp[s[pre] - 'a'];
                    u = std::max(u, j - pre);
                    pre = j;
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 26; ++ i){
        max = std::max(max, dp[i]);
    }
    printf("%d\n", max);
    return 0;
}