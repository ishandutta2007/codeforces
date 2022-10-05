#include <bits/stdc++.h>

const int N = 110;

std::string s[N];
bool vis[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        std::cin >> s[i];
    }
    std::string ans, ans1, ans2;
    for (int i = 0; i < n; ++ i){
        if (vis[i]){
            continue;
        }
        std::string rev = s[i];
        for (int j = 0, k = rev.size() - 1; j < k; ++ j, -- k){
            std::swap(rev[j], rev[k]);
        }
        for (int j = i + 1; j < n; ++ j){
            if (vis[j]){
                continue;
            }
            if (s[j] == rev){
                ans1 += s[i];
                ans2 = s[j] + ans2;
                vis[i] = vis[j] = true;
                break;
            }
        }
        if (!vis[i] && s[i] == rev && ans.empty()){
            ans = s[i];
        }
    }
    ans = ans1 + ans + ans2;
    std::cout << ans.size() << std::endl << ans << std::endl;
    return 0;
}