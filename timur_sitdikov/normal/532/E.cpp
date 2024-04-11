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

const int MAXN = 1e5 + 100;

char c1[MAXN], c2[MAXN], c3[MAXN], c4[MAXN];
int n, pos;

int check(char *s1, char *s2){
    int i;
    for(i = 0; s1[i] == s2[i]; i++);
    //printf("%d\n", i);
    for(; i < n && s1[i] == s2[i + 1]; i++);
    //printf("%d\n", i);
    if (i >= n){
        return 1;
    }
    return 0;
}

void solve(){
    int i;
    scanf("%d%s%s", &n, &c1[0], &c2[0]);
    for(pos = 0; c1[pos] == c2[pos]; pos++);
    for(i = 0; i < pos; i++){
        c3[i] = c1[i];
        c4[i] = c2[i];
    }
    c3[pos] = c2[pos];
    c4[pos] = c1[pos];
    for(i = pos; i < n; i++){
        c3[i + 1] = c1[i];
        c4[i + 1] = c2[i];
    }
    int ans = check(c2, c3) + check(c1, c4);
    printf("%d\n", ans);
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