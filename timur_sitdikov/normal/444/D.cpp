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

const int MAXN = 1e6;
const int INF = 1e9;

vector<int> s[MAXN];

char c[MAXN];

map<pii, int> aa;

int get_h(char *c, int lim){
    int ans = 0;
    for(int i = 0; i < lim; i++){
        ans = ans * 27 + (c[i] - 'a' + 1);
    }
    return ans;
}

int get(int v1, int l1, int v2, int l2){
    if (s[v1].size() > s[v2].size()){
        swap(v1, v2);
        swap(l1, l2);
    }
    int ans = INF, i;
    //printf("%d %d\n", s[v1].size(), s[v2].size());
    for(i = 0; i < (int)s[v1].size(); i++){
        int l = s[v1][i], r;
        int tmp = lower_bound(s[v2].begin(), s[v2].end(), l) - s[v2].begin();
        //printf("* %d\n", tmp);
        if (tmp < s[v2].size()){
            //printf("#\n");
            r = max(s[v2][tmp] + l2, l + l1);
            ans = min(ans, r - l);
        }
        tmp--;
        if (tmp != -1){
            int _l = s[v2][tmp], _r = max(l + l1, s[v2][tmp] + l2);
            ans = min(ans, _r - _l);
        }
    }
    return ans;
}

void solve(){
    char c1[10], c2[10];
    int n, i, j, k, q;
    scanf("%s%d", &c[0], &q);
    n = strlen(c);
    for(j = 1; j <= 4; j++){
        for(i = 0; i + j <= n; i++){
            int v = get_h(&c[i], j);
            s[v].pb(i);
        }
    }
    for(; q; q--){
        scanf("%s%s", &c1[0], &c2[0]);
        int l1 = strlen(c1), l2 = strlen(c2);
        int v1 = get_h(c1, l1), v2 = get_h(c2, l2);
        if (v1 > v2){
            swap(v1, v2);
            swap(l1, l2);
        }
        if (aa.find(mp(v1, v2)) != aa.end()){
            printf("%d\n", aa[mp(v1, v2)]);
            continue;
        }
        int ans = get(v2, l2, v1, l1);
        if (ans == INF){
            ans = -1;
        }
        aa[mp(v1, v2)] = ans;
        printf("%d\n", ans);
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