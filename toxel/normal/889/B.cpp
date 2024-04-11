#include<bits/stdc++.h>

const int N = 100010;
const int M = 30;

std::string str[N];
int vis[M];
char tmp[N];
int cnt[M];

bool valid(std::string &s){
    if ((int) s.size() > 26){
        return false;
    }
    memset(cnt, 0, sizeof(cnt));
    for (auto ch : s){
        ++ cnt[ch - 'a'];
    }
    for (int i = 0; i < 26; ++ i){
        if (cnt[i] > 1){
            return false;
        }
    }
    return true;
}

std::string merge(std::string s1, std::string s2){
    int sz1 = s1.size();
    int sz2 = s2.size();
    for (int i = 0; i < sz1; ++ i){
        bool flag = true;
        for (int j = 0, sz = std::min(sz1 - i, sz2); j < sz; ++ j){
            if (s1[i + j] != s2[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            for (int j = 0; j < sz1; ++ j){
                tmp[j] = s1[j];
            }
            for (int j = sz1; j < i + sz2; ++ j){
                tmp[j] = s2[j - i];
            }
            tmp[std::max(i + sz2, sz1)] = '\0';
            std::string ans = tmp;
            if (valid(ans)){
                return ans;
            }
        }
    }
    return std::string();
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", tmp);
        str[i] = tmp;
    }
    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < n; ++ i){
        if (!valid(str[i])){
            puts("NO");
            return 0;
        }
        while (true){
            bool flag = false;
            for (auto ch : str[i]){
                if (vis[ch - 'a'] != -1){
                    std::string tmp = merge(str[i], str[vis[ch - 'a']]);
                    if (tmp.empty()){
                        tmp = merge(str[vis[ch - 'a']], str[i]);
                    }
                    str[i] = tmp;
                    if (str[i].empty()){
                        puts("NO");
                        return 0;
                    }
                    flag = true;
                    vis[ch - 'a'] = -1;
                    break;
                }
            }
            if (!flag){
                break;
            }
        }
        for (auto ch : str[i]){
            vis[ch - 'a'] = i;
        }
    }
    std::set <std::string> set;
    for (int i = 0; i < 26; ++ i){
        if (vis[i] != -1){
            set.insert(str[vis[i]]);
        }
    }
    std::string ans;
    for (auto u : set){
        ans += u;
    }
    printf("%s\n", ans.c_str());
    return 0;
}