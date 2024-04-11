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
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

#define FILE "file"

const int MAXN = 105;

int core[MAXN], mem[MAXN];

int g[MAXN][MAXN];
vector<int> bads;

void solve(){
    int n, m, k, i, j, l;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    }
    for(j = 1; j <= m; j++){
        bads.clear();
        for(i = 1; i <= n; i++){
            if (core[i] || !g[i][j]){
                continue;
            }
            if (mem[g[i][j]]){
                core[i] = j;
                continue;
            }
            for(l = 1; l <= n; l++){
                if (l != i && !core[l] && g[l][j] == g[i][j]){
                    bads.pb(i);
                    break;      
                }
            }
        }
        for(i = 0; i < (int)bads.size(); i++){
            core[bads[i]] = j;
            mem[g[bads[i]][j]] = 1;
        }
    }
    for(i = 1; i <= n; i++){
        cout << core[i] << endl;
    }
}

int main(){ 
    //assert(freopen("in.txt", "r", stdin));assert(freopen("out.txt", "w", stdout));
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}