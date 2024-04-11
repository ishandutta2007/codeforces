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

const int MAXN = 505;

char c[MAXN][MAXN];
int used[MAXN][MAXN];
queue<pair<int, int>> qq;
int k, n, m;
vector<pair<int, int> > vv;

void bfs(){
    int i, j, i0, j0, i1, j1;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if (c[i][j] == '.'){
                i0 = i;
                j0 = j;
            }
        }
    }
    used[i0][j0] = 1;
    qq.push(mp(i0, j0));
    while(!qq.empty()){
        i0 = qq.front().first;
        j0 = qq.front().second;
        vv.pb(mp(i0, j0));
        qq.pop();
        for(i = -1; i <= 1; i++){
            for(j = -1; j <= 1; j++){
                if (abs(i + j) == 1){
                    i1 = i0 + i;
                    j1 = j0 + j;
                    if (!used[i1][j1] && c[i1][j1] == '.'){
                        used[i1][j1] = 1;
                        qq.push(mp(i1, j1));
                    }
                }
            }
        }
    }
    for(i = vv.size() - 1, j = 0; j < k; j++, i--){
        i0 = vv[i].first;
        j0 = vv[i].second;
        c[i0][j0] = 'X';
    }
}

void solve(){
    int i, j, s;
    scanf("%d%d%d", &n, &m, &k);
    for(i = 1; i <= n; i++){
        scanf("%s", &c[i][1]);
    }
    bfs();
    for(i = 1; i <= n; i++){
        printf("%s\n", &c[i][1]);
    }
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}