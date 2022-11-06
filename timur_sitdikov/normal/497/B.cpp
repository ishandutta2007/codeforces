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

int v[MAXN], sum[2][MAXN];

vector<pii> ans;

void solve(){
    int n, i, j[2], k[2], t, s, cnt[2], last, ind, lastk;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
        v[i]--;
        sum[0][i] = sum[0][i - 1];
        sum[1][i] = sum[1][i - 1];
        sum[v[i]][i]++;
    }
    //sum[0][n + 1] = sum[1][n + 1] = INF;
    for(t = 1; t <= n; t++){
        cnt[0] = cnt[1] = 0;
        last = -1;
        lastk = 0;
        for(j[0] = j[1] = 0; j[0] < n || j[1] < n; ){
            for(i = 0; i < 2; i++){
                k[i] = lower_bound(sum[i] + j[i], sum[i] + n + 1, sum[i][j[i]] + t) - sum[i];
            }
            if (k[0] == k[1] && k[0] == n + 1){
                //j[0] = j[1] = n + 1;
                break;
            }
            if (k[0] < k[1]){
                ind = 0;
            } else {
                ind = 1;
            }
            cnt[ind]++;
            last = ind;
            j[0] = j[1] = k[ind];
            lastk = k[ind];
        }
        if (lastk == n && last != -1 && cnt[last] > cnt[last ^ 1]){
            ans.pb(mp(cnt[last], t));
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(i = 0; i < (int)ans.size(); i++){
        printf("%d %d\n", ans[i].first, ans[i].second);
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