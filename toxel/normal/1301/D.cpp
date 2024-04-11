#include <bits/stdc++.h>

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int sum = 4 * n * m - 2 * n - 2 * m;
    if (k > sum){
        puts("NO");
        return 0;
    }
    puts("YES");
    std::vector <std::string> ans;
    for (int i = 0; i < n - 1; ++ i){
        for (int j = 0; j < m - 1; ++ j){
            ans.emplace_back("R");
        }
        for (int j = 0; j < m - 1; ++ j){
            ans.emplace_back("DUL");
        }
        ans.emplace_back("D");
    }
    for (int j = 0; j < m - 1; ++ j){
        ans.emplace_back("R");
    }
    for (int j = 0; j < m - 1; ++ j){
        ans.emplace_back("L");
    }
    for (int j = 0; j < n - 1; ++ j){
        ans.emplace_back("U");
    }
    int cur = sum;
    while (cur > k){
        if (cur - ans.back().size() >= k){
            cur -= ans.back().size();
            ans.pop_back();
        }
        else{
            auto &u = ans.back();
            u = u.substr(0, u.size() - (cur - k));
            break;
        }
    }
    int sz = ans.size();
    std::vector <std::string> print;
    for (int i = 0, j = 0; i < sz; i = j){
        while (j < sz && ans[j] == ans[i]){
            ++ j;
        }
        char result[100];
        sprintf(result, "%d %s\n", j - i, ans[i].c_str());
        print.emplace_back(result);
    }
    printf("%d\n", int(print.size()));
    for (auto u : print){
        printf("%s", u.c_str());
    }
    return 0;
}