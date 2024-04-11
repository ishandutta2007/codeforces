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

vector<int> g[MAXN];
int st[MAXN];
int st_n[MAXN];


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, a, b, i;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
        st[a]++;
        st[b]++;
    }
    for(i = 1; i <= n; i++){
        st_n[st[i]]++;
    }
    if (st_n[2] == n){
        printf("ring topology");
        return 0;
    }
    if (st_n[2] == n - 2 && st_n[1] == 2){
        printf("bus topology");
        return 0;
    }
    if (st_n[1] == n - 1 && st_n[n - 1] == 1){
        printf("star topology");
        return 0;
    }
    printf("unknown topology");
    
}