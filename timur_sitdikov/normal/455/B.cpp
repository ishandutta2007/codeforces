#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

const int MAXN = 2e5 + 5;

char c[MAXN];
int g[MAXN][26], col[MAXN], is_f[MAXN];
int used[3];

void dfs(int s){
    int i, to, fl[4];
    for(i = 0; i < 4; i++){
        fl[i] = 0;
    }
    for(i = 0; i < 26; i++){
        to = g[s][i];
        if (to){
            dfs(to);
            fl[col[to]] = 1;
        }
    }
    if (fl[3] || fl[0] && fl[1]){
        col[s] = 2;
    } else if (fl[0]){
        col[s] = 1;
    } else if (fl[1]){
        col[s] = 0;
    } else if (fl[2]){
        col[s] = 3;
    }
    /*for(i = 0; i < 3; i++){
        used[i] = 0;
    }
    for(i = 0; i < 26; i++){
        to = g[s][i];
        if (to){
            used[col[to]] = 1;
        }
    }
    for(i = 0; i < 3; i++){
        if (!used[i]){
            break;
        }
    }
    i = min(i, 2);
    col[s] = i;*/   
}

void solve(){
    int n, i, j, s, top = 1, k;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%s", &c[0]);
        for(s = 0, j = 0; c[j]; j++){
            if (g[s][c[j] - 'a']){
                s = g[s][c[j] - 'a'];
            } else {
                g[s][c[j] - 'a'] = top;
                s = top++;
            }
        }
        //is_f[s] = 1;
    }
    dfs(0);
    if (col[0] == 3 || col[0] == 0 || col[0] == 1 && k % 2 == 0){
        printf("Second\n");
    } else {
        printf("First\n");
    }
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}