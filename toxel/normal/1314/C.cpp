#include <bits/stdc++.h>

const int N = 1010;
const int M = N * N / 2;
const int SIGMA = 26;
using ll = long long;
const ll INF = 1.1e18;

ll add(ll a, ll b){
    return std::min(INF, a + b);
}

struct Trie{
    Trie *ch[SIGMA]{}, *fa{};
    char fa_ch{};
    bool vis{};
};

Trie *trie_pool, *root;
int trie_num;

Trie *new_trie(){
    if (!trie_num){
        trie_pool = new Trie[M];
        trie_num = M;
    }
    return trie_pool + -- trie_num;
}

void insert(char *s){
    Trie *p = root;
    while (*s != '\0'){
        p -> vis = true;
        int pos = *s - 'a';
        if (p -> ch[pos] != nullptr){
            p = p -> ch[pos];
        }
        else{
            Trie *cur = p;
            p = p -> ch[pos] = new_trie();
            p -> fa = cur;
            p -> fa_ch = *s;
        }
        ++ s;
    }
    p -> vis = true;
}

char s[N], t[N];
Trie *sub_str[M];
int sub_str_cnt;
ll dp[N][N];

void dfs(Trie *p){
    if (p -> vis){
        sub_str[sub_str_cnt ++] = p;
    }
    for (int i = 0; i < SIGMA; ++ i){
        if (p -> ch[i] != nullptr){
            dfs(p -> ch[i]);
        }
    }
}

void get(Trie *p){
    char *q = t;
    while (p != root){
        *(q ++) = p -> fa_ch;
        p = p -> fa;
    }
    *q = '\0';
    std::reverse(t, q);
}

int lcp(char *p, char *q){
    char *begin_p = p;
    while (*p != '\0'){
        if (*p < *q){
            return -1;
        }
        if (*p > *q){
            return int(p - begin_p);
        }
        ++ p, ++ q;
    }
    return -1;
}

ll calc(int split){
    int n = strlen(s), m = strlen(t);
    memset(dp, 0, sizeof(dp));
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; -- i){
        if (i > 0){
            memcpy(dp[i], dp[i + 1], sizeof(dp[i]));
        }
        int begin = lcp(s + i, t);
        if (begin >= 0){
            for (int j = 1; j < N; ++ j){
                dp[i][j] = add(dp[i][j], dp[i + begin + 1][j - 1]);
            }
        }
    }
    //printf("%s %d\n", t, dp[0][split]);
    return dp[0][split];
}

int main(){
    root = new_trie();
    int n, m;
    ll k;
    scanf("%d%d%lld%s", &n, &m, &k, s);
    for (int i = 0; i < n; ++ i){
        insert(s + i);
    }
    dfs(root);
    int left = 0, right = sub_str_cnt;
    /*for (int i = 0; i < sub_str_cnt; ++ i){
        get(sub_str[i]);
        printf("%s\n", t);
    }*/
    while (left < right){
        int mid = (left + right) / 2;
        get(sub_str[mid]);
        if (calc(m) >= k){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    get(sub_str[left]);
    printf("%s\n", t);
    return 0;
}