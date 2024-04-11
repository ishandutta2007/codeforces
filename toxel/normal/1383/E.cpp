#include <bits/stdc++.h>

const int N = 1000010;
const int moder = int(1e9) + 7;

char s[N];
int right[N], dp[N];
int value[N];

void add(int &a, int b){
    a += b, a -= a >= moder ? moder : 0;
}

void sub(int &a, int b){
    a -= b, a += a < 0 ? moder : 0;
}

std::set <std::string> set[N];

int bf(){
    int n = strlen(s);
    set[0].insert("");
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= i; ++ j){
            char next = '0';
            for (int k = j; k <= i; ++ k){
                if (s[k] == '1'){
                    next = '1';
                    break;
                }
            }
            for (auto u : set[j]){
                set[i + 1].insert(u + next);
            }
        }
    }
    return set[n].size();
}

int main(){
    scanf("%s", s);
    int n = strlen(s);
    right[n] = n;
    for (int i = n - 1; i >= 0; -- i){
        right[i] = s[i] == '1' ? i : right[i + 1];
    }
    int sum = 0;
    int last = 0;
    for (int i = n - 1; i >= 0; -- i){
        if (s[i] == '1'){
            break;
        }
        ++ last;
    }
    for (int i = n - 1; i >= 0; -- i){
        if (s[i] == '0'){
            int cnt = right[i] - i;
            if (right[i] < n){
                sub(sum, value[cnt]);
                value[cnt] = dp[right[i]];
                add(sum, value[cnt]);
            }
        }
        dp[i] = 1;
        if (s[i] == '0'){
            add(dp[i], dp[i + 1]);
            if (right[i] < n){
                add(dp[i], dp[right[i]]);
                sub(dp[i], 1);
            }
        }
        else{
            if (right[i + 1] < n){
                add(dp[i], dp[right[i + 1]]);
            }
            add(dp[i], sum);
            add(dp[i], last);
        }
    }
    printf("%d\n", dp[0]);
    //printf("%d\n", bf());
    return 0;
}