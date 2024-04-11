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

const int MAXN = 100005;

pair<int, int> par[MAXN];
int nxt[MAXN], b[MAXN], v[MAXN], ans[MAXN];

pair<int, int> find_set(int v){
    if (par[v].first == v){
        return par[v];
    }
    pair<int, int> tmp = find_set(par[v].first);
    par[v].second += tmp.second;
    par[v].first = tmp.first;
    return par[v];
}

void union_sets(int a, int b){
    pair<int, int> tmp = find_set(b);
    par[a] = tmp;
    par[a].second++;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int i, j, n, m, a, res;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", &nxt[i]);
        par[i] = mp(i, 0);
    }
    for(i = 1; i <= m; i++){
        scanf("%d", &v[i]);
    }
    for(i = 1; i <= m; i++){
        scanf("%d", &b[i]);
    }
    res = 0;
    pair<int, int> tmp;
    for(j = 1; j <= m; j++){
        a = (v[j] + res - 1) % n + 1;
        res = 0;
        for(i = a; b[j] > 0; ){
            tmp = find_set(i);
            i = tmp.first;
            b[j] -= tmp.second;
            if (b[j] <= 0)
                break;
            if (ans[i] == 0){
                ans[i] = j;
                res++;
            }
            if (par[nxt[i]].first == i)
                break;
            /*if (b[j] == 0)
                break;*/
            b[j]--;
            union_sets(i, nxt[i]);
            i = nxt[i];
        }
        printf("%d\n", res);
    }
}