#include<bits/stdc++.h>

const int N = 1000010;
const int AND = 0;
const int OR = 1;
const int XOR = 2;
const int NOT = 3;
const int IN = 4;

int value[N], bro[N];
int type[N];
int change[N];
std::vector <int> e[N];
char s[N];

void dfs(int u){
    for (auto v : e[u]){
        dfs(v);
    }
    if (type[u] == IN){
        return;
    }
    if (type[u] == NOT){
        value[u] = 1 ^ value[e[u][0]];
    }
    else if (type[u] == AND){
        value[u] = value[e[u][0]] & value[e[u][1]];
    }
    else if (type[u] == OR){
        value[u] = value[e[u][0]] | value[e[u][1]];
    }
    else if (type[u] == XOR){
        value[u] = value[e[u][0]] ^ value[e[u][1]];
    }
    if ((int) e[u].size() == 2){
        for (int i = 0; i < 2; ++ i){
            bro[e[u][i]] = e[u][i ^ 1];
        }
    }
}

void solve(int u, int fa){
    if (u == 1){
        change[u] = 1;
    }
    else if (type[fa] == XOR || type[fa] == NOT){
        change[u] = change[fa];
    }
    else if (type[fa] == AND){
        change[u] = value[bro[u]] == 1 ? change[fa] : u;
    }
    else if (type[fa] == OR){
        change[u] = value[bro[u]] == 0 ? change[fa] : u;
    }
    for (auto v : e[u]){
        solve(v, u);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%s", s);
        int x, y;
        if (s[0] == 'A'){
            type[i] = AND;
            scanf("%d%d", &x, &y);
            e[i].push_back(x);
            e[i].push_back(y);
        }
        else if (s[0] == 'O'){
            type[i] = OR;
            scanf("%d%d", &x, &y);
            e[i].push_back(x);
            e[i].push_back(y);
        }
        else if (s[0] == 'X'){
            type[i] = XOR;
            scanf("%d%d", &x, &y);
            e[i].push_back(x);
            e[i].push_back(y);
        }
        else if (s[0] == 'N'){
            type[i] = NOT;
            scanf("%d", &x);
            e[i].push_back(x);
        }
        else if (s[0] == 'I'){
            type[i] = IN;
            scanf("%d", &value[i]);
        }
    }
    dfs(1);
    solve(1, 0);
    for (int i = 1; i <= n; ++ i){
        if (type[i] == IN){
            printf("%d", value[1] ^ (change[i] == 1));
        }
    }
    puts("");
    return 0;
}