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

const int MAXN = 105;

vector<int> v1, v2, v, vv, bad;

int dp[MAXN][MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    int i, j, k, a, n, m, ans;
    cin >> n >> m;
    for(i = 0; i < n; i++){
        cin >> s >> a;
        if (s[0] == 'D'){
            v2.pb(a);
            vv.pb(a + 1);
        }
        else{
            v1.pb(a);
            vv.pb(a);
        }
    }
    for(i = 0; i < m; i++){
        cin >> a;
        v.pb(a);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    sort(vv.begin(), vv.end());
    reverse(vv.begin(), vv.end());
    bad.assign(m, 0);
    ans = 0;
    if (n <= m){
        for(i = 0; i < n; i++){
            if (vv[i] > v[i])
                break;
        }
        if (i == n){
            for(i = v2.size() - 1; i >= 0; i--){
                for(j = v.size() - 1; j >= 0; j--){
                    if (!bad[j] && v[j] > v2[i]){
                        bad[j] = 1;
                        break;
                    }
                }
            }
            int s1 = 0, s2 = 0;
            for(i = 0; i < (int)v.size(); i++){
                if (!bad[i]){
                    s1 += v[i];
                }
            }
            for(i = 0; i < (int)v1.size(); i++){
                s2 += v1[i];
            }
            ans = max(ans, s1 - s2);
        }
    }
    reverse(v.begin(), v.end());
    reverse(v1.begin(), v1.end());
    for(i = 0; i < (int)v.size(); i++){
        for(j = 0; j < (int)v1.size(); j++){
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
            if (v[i] >= v1[j]){
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + v[i] - v1[j]);
            }
        }
    }
    ans = max(ans, dp[v.size()][v1.size()]);
    cout << ans;
}