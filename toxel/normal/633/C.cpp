#include<bits/stdc++.h>

struct trie{
    int exist;
    trie *child[26];

    trie():exist(-1){for (int i = 0; i < 26; ++ i){child[i] = nullptr;}}
};

const int N = 100010;

std::string str[N];
int triecnt;
trie *triepool;
int n;
char s[N], tmp[N];
bool dp[N];
int pre[N];

trie *newtrie(){
    if (!triecnt){
        triepool = new trie[N];
        triecnt = N;
    }
    return triepool + -- triecnt;
}

int main(){
    int n, m;
    scanf("%d%s%d", &n, s, &m);
    trie *root = newtrie();
    for (int i = 0; i < m; ++ i){
        scanf("%s", tmp);
        str[i] = tmp;
        trie *p = root;
        for (auto u : str[i]){
            if (u >= 'A' && u <= 'Z') u = u - 'A' + 'a';
            if (p -> child[u - 'a'] == nullptr){
                p -> child[u - 'a'] = newtrie();
            }
            p = p -> child[u - 'a'];
        }
        p -> exist = i;
    }
    dp[0] = true;
    for (int i = 0; i < n; ++ i){
        trie *p = root;
        int cnt = 0;
        while (i - cnt >= 0){
            p = p -> child[s[i - cnt] - 'a'];
            if (p == nullptr) break;
            if (dp[i - cnt] && p -> exist != -1){
                dp[i + 1] = true;
                pre[i + 1] = p -> exist;
            }
            ++ cnt;
        }
    }
    std::vector <std::string> ans;
    int now = n;
    while (now){
        ans.push_back(str[pre[now]]);
        now = now - str[pre[now]].size();
    }
    std::reverse(ans.begin(), ans.end());
    for (int i = 0, sz = ans.size(); i < sz; ++ i){
        printf("%s%c", ans[i].c_str(), " \n"[i == sz - 1]);
    }
    return 0;
}