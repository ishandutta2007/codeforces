#include <bits/stdc++.h>

const int MAXNODE = 20010;
const int DICSIZE = 10;
const int N = 2010;
typedef long long ll;

int go[MAXNODE][DICSIZE], fail[MAXNODE];
int sz, root;
int wildcard[MAXNODE][N];

int newnode(){
    int ret = ++ sz;
    memset(go[ret], 0, sizeof(go[ret]));
    fail[ret] = root;
    return ret;
}

void init(){
    root = 0;
    sz = 0;
    root = newnode();
}

void insert(int &node, char ch, int suffix = -1){
    int c = ch - '0';
    if (!go[node][c]){
        go[node][c] = newnode();
    }
    node = go[node][c];
    if (suffix != -1){
        ++ wildcard[node][suffix];
    }
}

void makefail(){
    for (int i = 0; i < MAXNODE; ++ i){
        for (int j = 1; j < N; ++ j){
            wildcard[i][j] += wildcard[i][j - 1];
        }
    }
    std::queue<int> queue;
    queue.push(root);
    while(!queue.empty()){
        int p = queue.front(); queue.pop();
        for(int i = 0; i < DICSIZE; ++ i){
            if(go[p][i]){
                fail[go[p][i]] = fail[p] ? go[fail[p]][i] : root;
                int q = go[p][i];
                queue.push(q);
                for (int j = 0; j < N; ++ j){
                    wildcard[q][j] += wildcard[fail[q]][j];
                }
            }
            else{
                go[p][i] = p == root ? root : go[fail[p]][i];
            }
        }
    }
}

char l[MAXNODE], r[MAXNODE];
int dp[2][MAXNODE], pre[N][MAXNODE];
char prech[N][MAXNODE];
ll order[2][MAXNODE];
ll c[MAXNODE];
char ans[N];

int main(){
    init();
    scanf("%s%s", l, r);
    int lenl = strlen(l), lenr = strlen(r);
    if (lenl == lenr){
        int n = lenl;
        int node = root;
        for (int i = 0; i < n; ++ i){
            if (i < n - 1 && l[i] == r[i]){
                insert(node, l[i]);
            }
            else{
                int lnode = node, rnode = node;
                if (i == n - 1) {
                    for (int j = l[i]; j <= r[i]; ++j) {
                        insert(node, j, 0);
                        node = lnode;
                    }
                    break;
                }
                for (int j = l[i] + 1; j <= r[i] - 1; ++ j){
                    insert(node, j, n - i - 1);
                    node = lnode;
                }
                for (int j = i + 1; j < n; ++ j){
                    insert(lnode, l[j - 1]);
                    insert(rnode, r[j - 1]);
                    for (int k = '0'; k <= r[j] + (j == n - 1 ? 0 : -1); ++ k) {
                        int tmp = rnode;
                        insert(rnode, k, n - j - 1);
                        rnode = tmp;
                    }
                    for (int k = l[j] + (j == n - 1 ? 0 : 1); k <= '9'; ++ k){
                        int tmp = lnode;
                        insert(lnode, k, n - j - 1);
                        lnode = tmp;
                    }
                }
                break;
            }
        }
    } else{
        int node = root;
        for (int i = lenl + 1; i < lenr; ++ i){
            for (int j = '1'; j <= '9'; ++ j) {
                insert(node, j, i - 1);
                node = root;
            }
        }
        node = root;
        for (int i = 0; i < lenl; ++ i) {
            if (i) {
                insert(node, l[i - 1]);
            }
            for (int j = l[i] + (i == lenl - 1 ? 0 : 1); j <= '9'; ++ j){
                int tmp = node;
                insert(node, j, lenl - i - 1);
                node = tmp;
            }
        }
        node = root;
        for (int i = 0; i < lenr; ++ i) {
            if (i) {
                insert(node, r[i - 1]);
            }
            for (int j = i ? '0' : '1'; j <= r[i] + (i == lenr - 1 ? 0 : -1); ++j) {
                int tmp = node;
                insert(node, j, lenr - i - 1);
                node = tmp;
            }
        }
    }
    makefail();
    memset(dp, -1, sizeof(dp));
    memset(order, -1, sizeof(order));
    dp[0][root] = order[0][root] = 0;
    int now = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        memset(dp[now ^ 1], -1, sizeof(dp[now]));
        memset(order[now ^ 1], -1, sizeof(order[now]));
        for (int j = 0; j < MAXNODE; ++ j){
            if (dp[now][j] == -1){
                continue;
            }
            for (int k = 0; k < 10; ++ k){
                int nj = go[j][k];
                int nvalue = dp[now][j] + wildcard[nj][n - i];
                ll norder = order[now][j] * 10 + k;
                if (nvalue > dp[now ^ 1][nj] || (nvalue == dp[now ^ 1][nj] && order[now ^ 1][nj] > norder)){
                    dp[now ^ 1][nj] = nvalue;
                    order[now ^ 1][nj] = norder;
                    pre[i][nj] = j;
                    prech[i][nj] = '0' + k;
                }
            }
        }
        now ^= 1;
        if (i % 10 == 0){
            int cnt = 0;
            for (int j = 0; j < MAXNODE; ++ j){
                if (order[now][j] != -1){
                    c[cnt ++] = order[now][j];
                }
            }
            std::sort(c, c + cnt);
            cnt = std::unique(c, c + cnt) - c;
            for (int j = 0; j < MAXNODE; ++ j){
                if (order[now][j] != -1){
                    order[now][j] = std::lower_bound(c, c + cnt, order[now][j]) - c;
                }
            }
        }
    }
    int max = 0, sit = 0;
    ll minorder = LLONG_MAX;
    for (int i = 0; i < MAXNODE; ++ i){
        if (dp[now][i] > max || (dp[now][i] == max && order[now][i] < minorder)){
            max = dp[now][i];
            minorder = order[now][i];
            sit = i;
        }
    }
    for (int i = n; i >= 1; -- i){
        ans[i] = prech[i][sit];
        sit = pre[i][sit];
    }
    printf("%d\n", max);
    puts(ans + 1);
    return 0;
}