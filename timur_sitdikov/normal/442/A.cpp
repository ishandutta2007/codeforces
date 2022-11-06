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

const int MAXN = 105;

int v[MAXN];
char s[MAXN][5];

int val[200];

void solve(){
    int i, j, k;
    val['R'] = 5;
    val['G'] = 6;
    val['B'] = 7;
    val['Y'] = 8;
    val['W'] = 9;
    for(i = '1'; i <= '5'; i++){
        val[i] = i - '1';
    }
    int n;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", &s[i][0]);
        s[i][0] = val[s[i][0]];
        s[i][1] = val[s[i][1]];
    }
    int ans = 100;
    for(i = 0; i < (1 << 10); i++){
        int fl = 0, fl1 = 0;
        for(j = 0; j < n; j++){
            val[j] = 0;
        }
        for(j = 0; j < n; j++){
            for(k = j + 1; k < n; k++){
                if (s[j][0] != s[k][0] || s[j][1] != s[k][1]){
                    fl1 = 0;
                    if (s[j][0] != s[k][0] && ((i & (1 << s[j][0])) ||(i & (1 << s[k][0])))){
                        fl1 = 1;
                    }
                    if (s[j][1] != s[k][1] && ((i & (1 << s[j][1])) || (i & (1 << s[k][1])))){
                        fl1 = 1;
                    }
                    if (fl1 == 0){
                        fl = 1;
                    }
                }
            }
        }
        if (!fl){
            int cnt = 0;
            for(j = 0; j < 10; j++){
                if (i & (1 << j)){
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
    }
    printf("%d\n", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1;
    while(t--){
        solve();    
    }
}