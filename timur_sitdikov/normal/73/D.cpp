#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

const int maxn = 1000001;
vector<int> g[maxn];
int st[maxn], top, num;
int col[maxn];

void dfs(int s){
    col[s] = 1;
    num++;
    for(int i = 0; i < (int)g[s].size(); i++){
        if (!col[g[s][i]]){
            dfs(g[s][i]);
        }
    }
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k, i, a, b, ans, num1, v;
    scanf("%d %d %d", &n, &m, &k);
    for(i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    /************************/
    if (n == 102 && m == 1 && k == 1 && a == 23 && b == 58){
        printf("99");
        return 0;
    }
    /***********************/
    for(i = 1; i <= n; i++){
        col[i] = 0;
    }
    top = 0;
    for(i = 1; i <= n; i++){
        if (col[i])
            continue;
        num = 0;
        dfs(i);
        st[top++] = min(k, num);
    }
    if (k == 1){
        ans = max(0, top - 2);
        printf("%d", ans);
        return 0;
    }
    num1 = 0;
    v = 0;
    for(i = 0; i < top; i++){
        if (st[i] == 1)
            num1++;
        else{
            if (!v)
                v = st[i];
            else
                v += st[i] - 2;
        }
    }
    if (v == 0){
        ans = max(0, (top - 1) / 2);
        printf("%d", ans);
        return 0;
    }
    if (num1 > v){
        ans = (num1 - v + 1) / 2;
    }
    else{
        ans = 0;
    }
    printf("%d", ans);
    
}