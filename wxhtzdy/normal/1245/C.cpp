#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
const int MOD = 1e9 + 7;

int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B;}

char s[N];
int dp[N];

int main(){
        scanf("%s", s);
        int n = strlen(s);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
                dp[i] = dp[i - 1];
                if(s[i - 1] == 'm' || s[i - 1] == 'w') return 0 * printf("0");
                if(i == 1) continue;
                if((s[i - 1] == 'n' || s[i - 1] == 'u') && s[i - 2] == s[i - 1]){
                        dp[i] = add(dp[i], dp[i - 2]);
                }
                
        }
        printf("%d", dp[n]);
        return 0;
}