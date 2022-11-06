#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 205;
int g[MAXN][MAXN];
vector<int> vv;
int ans[MAXN][MAXN], top, tp[MAXN];
int col[MAXN], used[MAXN];

void dfs(int s){
    col[s] = 1;
    ans[top][tp[top]++] = s;
    for(int i = 1; i <= 200; i++){
        if (g[s][i] > 1 && !col[i]){
            dfs(i);
        }
    }
}
    
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, sz, k, a;
    cin >> n;
    for(i = 0; i < n* (n - 1) / 2; i++){
        cin >> sz;
        vv.clear();
        for(j = 0; j < sz; j++){
            cin >> a;
            used[a] = 1;
            vv.pb(a);
        }
        for(j = 0; j < sz; j++){
            for(k = j + 1; k < sz; k++){
                g[vv[j]][vv[k]]++;
                g[vv[k]][vv[j]]++;
            }
        }
    }
    if (n == 2){
        printf("1 %d\n%d ", vv[0], sz - 1);
        for(i = 1; i < sz; i++){
            printf("%d ", vv[i]);
        }
        return 0;
    }
    for(i = 1; i <= 200; i++){
        if (!used[i])
            continue;
        if (!col[i]){
            dfs(i);
            top++;
        }
    }
    for(i = 0; i < top; i++){
        printf("%d ", tp[i]);
        for(j = 0; j < tp[i]; j++){
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }
}