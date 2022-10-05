#include <bits/stdc++.h>

const int N = 100010;

char s[N];
bool output[N];
bool dp[N];
int pre[N];
int pre1[N];

void print(){
    std::vector <int> vec;
    for (int i = 0; i < N; ++ i){
        if (output[i]){
            int x = i;
            while (x < N && output[x]){
                ++ x;
            }
            vec.emplace_back(x - i);
            i = x;
        }
    }
    int sz = vec.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", vec[i], " \n"[i == sz - 1]);
    }
}

int main(){
    scanf("%s", s);
    int n = strlen(s);
    bool flag = s[0] == '#' && s[n - 1] == '#';
    for (int i = 0; i < n - 1; ++ i){
        if (s[i] == '_' && s[i + 1] == '_'){
            flag = false;
            break;
        }
    }
    if (flag){
        for (int i = 0; i < n; ++ i){
            output[i] = s[i] == '#';
        }
        print();
        return 0;
    }
    flag = true;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '#'){
            flag = false;
            break;
        }
    }
    if (flag){
        for (int i = 0; i < n; ++ i){
            output[i] = false;
        }
        print();
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        pre1[i] = pre1[i - 1] + (s[i - 1] == '#');
    }
    for (int len = 2; len <= 7 && len < n; ++ len){
        flag = true;
        for (int i = 0; i < len - 1; ++ i){
            if (s[i] != '_'){
                flag = false;
                break;
            }
            // if (s[n - 1 - i] != '_'){
            //     flag = false;
            //     break;
            // }
        }
        if (!flag){
            continue;
        }
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        dp[0] = true;
        auto getlen = [&](int start){
            return start == 0 || start == n - len + 1 ? len - 1 : len;
        };
        auto check = [&](int start){
            int len = getlen(start);
            if (start + len > n){
                return false;
            }
            return pre1[start + len] - pre1[start] == 0;
        };
        for (int i = 0; i < n; ++ i){
            if (!dp[i]){
                continue;
            }
            int length = getlen(i);
            if (s[i + length] == '#'){
                int x = i + length;
                while (x < n && s[x] == '#'){
                    ++ x;
                }
                if (check(x)){
                    dp[x] = true;
                    pre[x] = i;
                }
            }
            else{
                for (int j = i == 0 ? i + 1 : i + 2; j <= i + length; ++ j){
                    if (check(j)){
                        dp[j] = true;
                        pre[j] = i;
                    }
                }
            }
        }
        pre[0] = -1;
        if (dp[n - len + 1]){
            for (int i = 0; i < n - len + 1; ++ i){
                output[i] = true;
            }
            int cur = pre[n - len + 1];
            while (cur > 0){
                output[cur] = false;
                cur = pre[cur];
            }
            print();
            return 0;
        }
    }
    puts("-1");
    return 0;
}