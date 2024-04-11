#include <bits/stdc++.h>

const int N = 2000010;

std::vector <int> e[N];
char s[N];

void addedge(int u, int v){
    e[u].push_back(v);
    e[v].push_back(u);
}

bool solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n * 4; ++ i){
        e[i].clear();
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    scanf("%s", s + 1);
    int pcnt = n;
    for (int i = 1; i <= n; ++ i){
        if (s[i] == 'W'){
            addedge(i, pcnt + 1);
            addedge(pcnt + 1, pcnt + 2);
            addedge(pcnt + 1, pcnt + 3);
            pcnt += 3;
        }
    }
    std::vector <int> three;
    for (int i = 1; i <= pcnt; ++ i) {
        if (e[i].size() >= 4) {
            return true;
        }
        if (e[i].size() == 3){
            three.push_back(i);
        }
    }
    if (three.size() >= 3){
        return true;
    }
    for (auto u : three){
        int cnt = 0;
        for (auto v : e[u]){
            cnt += e[v].size() >= 2;
        }
        if (cnt >= 2){
            return true;
        }
    }
    return three.size() == 2 && pcnt % 2 == 1;
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        puts(solve() ? "White" : "Draw");
    }
    return 0;
}