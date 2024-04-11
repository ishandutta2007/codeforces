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

const int MAXN = 2e6 + 5;

char s[MAXN];
int pf[MAXN], z[MAXN], n, _left[MAXN], _right[MAXN];
char ans[MAXN];

void calc_z(){
    int i, l, r;
    for(i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r){
            z[i] = min (r -i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            ++z[i];
        }
        if (i + z[i] - 1 > r){
            l = i,  r = i + z[i] - 1;
        }
    }
}

void calc_pf(){
    int i, j;
    for(i = 1; i < n; i++){
        for(j = pf[i - 1]; j > 0 && s[i] != s[j]; j = pf[j - 1]);
        if (s[i] == s[j]){
            j++;
        }
        pf[i] = j;
    }
}

void solve(){
    int k, i;
    scanf("%d%d%s", &n, &k, &s[0]);
    calc_z();
    calc_pf();
    /*for(i = 0; i < n; i++){
        printf("%d %d\n", z[i], pf[i]);
    }*/
    for(i = 0; i < n; i++){
        int len = i - pf[i] + 1;
        if ((i + 1) % len){
            continue;
        }
        int cnt = (i + 1) / len;
        if (cnt % k){
            continue;
        }
        _left[i]++;
        int len2 = min(z[i + 1], len * cnt / k);
        _right[i + len2]++;
    }
    int dif = 0;
    for(i = 0; i < n; i++){
        dif += _left[i];
        if (dif > 0){
            ans[i] = '1';
        } else {
            ans[i] = '0';
        }
        dif -= _right[i];
    }
    printf("%s\n", ans);
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