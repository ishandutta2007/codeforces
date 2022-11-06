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

const int MAXN = 1000;

char s[MAXN];

void solve(){
    int n, i, j;
    scanf("%d%s", &n, &s[0]);
    for(i = 0; i < n; i++){
        for(j = 1; j < n; j++){
            if (s[i] == s[i + j] && s[i] == s[i + 2 * j] && s[i] == s[i + 3 * j] && s[i] == s[i + 4 * j] && s[i] == '*'){
                printf("yes\n");
                return;
            }
        }
    }
    printf("no\n");
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