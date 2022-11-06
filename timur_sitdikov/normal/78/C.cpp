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

const int MAXN = 1005;

vector<int> g[MAXN];
vector<int> divs;
vector<char> col;

void dfs(int s){
    col[s] = 2;
    int to;
    for(int i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (!col[to]){
            dfs(to);
        }
        if (col[to] == 2){
            col[s] = 1;
        }
    }
}

void output(int v){
    if (v == 1){
        printf("Timur");
    }
    else {
        printf("Marsel");
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, k, i, j, top;
    scanf("%d %d %d", &n, &m, &k);
    if (2 * k > m){
        output(2);
        return 0;
    }
    if (n % 2 == 0){
        output(2);
        return 0;
    }
    if (m % 2 == 0){
        output(1);
        return 0;
    }
    for(i = 1; i * i <= m; i++){
        if (m % i)
            continue;
        if (i >= k){
            divs.pb(i);
        }
        if (i * i != m && m / i >= k){
            divs.pb(m / i);
        }
    }
    top = divs.size();
    sort(divs.begin(), divs.end());
    for(i = 0; i < top; i++){
        for(j = i + 1; j < top; j++){
            if (divs[j] % divs[i])
                continue;
            g[j].pb(i);
        }
    }
    col.resize(top);
    dfs(top - 1);
    output(col[top - 1]);
}