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

const int MAXN = 1e5 + 5;

char c[MAXN];

ll cnt[2][2];

void solve(){
    int n, i, j, k;
    scanf("%s", &c[0]);
    n = strlen(c);
    for(i = 0; i < n; i++){
        if (c[i] == 'a'){
            cnt[0][i & 1]++;
        } else {
            cnt[1][i & 1]++;
        }
    }
    ll ans[2];
    ans[0] = cnt[0][0] * cnt[0][1] + cnt[1][0] * cnt[1][1];
    ans[1] = 0;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            ans[1] += cnt[i][j] * (cnt[i][j] + 1) / 2ll;
        }
    }
    cout << ans[0] << " " << ans[1] << endl;

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