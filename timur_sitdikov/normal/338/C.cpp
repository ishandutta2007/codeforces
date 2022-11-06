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
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

const int INF = 1e9;

struct Number{
    vector<pair<long long, int> > dd;
};

Number vals[10];
long long vv[10];
int is_pr[10];

int dp[1 << 8][1 << 8];
int add_dp[8][1 << 8];
vector<int> submasks[1 << 8], supmasks[1 << 8];

Number operator * (Number &a, Number &b){
    Number ans;
    int i, j;
    for(i = 0, j = 0; i < a.dd.size() && j < b.dd.size(); ){
        if (a.dd[i].first == b.dd[j].first){
            ans.dd.pb(mp(a.dd[i].first, a.dd[i].second + b.dd[j].second));
            i++;
            j++;
        }
        else if (a.dd[i].first < b.dd[j].first){
            ans.dd.pb(a.dd[i]);
            i++;
        }
        else {
            ans.dd.pb(b.dd[j]);
            j++;
        }
    }
    for(; i < a.dd.size(); i++){
        ans.dd.pb(a.dd[i]);
    }
    for(; j < b.dd.size(); j++){
        ans.dd.pb(b.dd[j]);
    }
    return ans;
}

int div_cnt(Number &a, Number &b){
    int i, j, ans = 0;
    for(i = 0, j = 0; i < a.dd.size() && j < b.dd.size(); ){
        if (a.dd[i].first == b.dd[j].first){
            if (a.dd[i].second < b.dd[j].second){
                return INF;
            }
            ans += a.dd[i].second - b.dd[j].second;
            i++;
            j++;
        }
        else if (a.dd[i].first < b.dd[j].first){
            ans += a.dd[i].second;
            i++;
        }
        else {
            return INF;
        }
    }
    if (j < b.dd.size()){
        return INF;
    }
    for(; i < a.dd.size(); i++){
        ans += a.dd[i].second;
    }
    return ans;
}

void get_number(int ind){
    long long i, a = vv[ind];
    int div_cnt = 0;
    for(i = 2; i * i <= a; i++){
        if (a % i == 0){
            int cnt = 0;
            while(a % i == 0){
                cnt++;
                a /= i;
            }
            div_cnt += cnt;
            vals[ind].dd.pb(mp(i, cnt));
        }
    }
    if (a > 1){
        vals[ind].dd.pb(mp(a, 1));
        div_cnt++;
    }
    if (div_cnt == 1){
        is_pr[ind] = 1;
    }
}

void solve(){
    int n, i, i1, maski, j, j1, maskj, k, maskk;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> vv[i];
        get_number(i);
    }
    for(i = 0; i < n; i++){
        if (is_pr[i]){
            int fl = 0;
            for(j = 0; j < n; j++){
                if (j == i){
                    continue;
                }
                if (vv[j] % vv[i] == 0){
                    vv[i] = vv[n - 1];
                    vals[i] = vals[n - 1];
                    is_pr[i] = is_pr[n - 1];
                    n--;
                    fl = 1;
                    break;
                }
            }
            if (fl == 1){
                i--;
            }
        }
    }
    for(i = 0; i < (1 << n); i++){
        for(j = 0; j < (1 << n); j++){
            dp[i][j] = INF;
        }
    }
    for(i = 0; i < n; i++){
        if (is_pr[i]){
            dp[1 << i][1 << i] = 1;
        }
        else {
            int sum = 1;
            for(k = 0; k < (int)vals[i].dd.size(); k++){
                sum += vals[i].dd[k].second;
            }
            dp[1 << i][1 << i] = sum;
        }
    }
    for(i = 0; i < (1 << n); i++){
        maski = i;
        for(; maski; maski = (i & (maski - 1))){
            submasks[i].pb(maski);
            //supmasks[maski].pb(i);
        }
        reverse(submasks[i].begin(), submasks[i].end());
    }
    for(i = 0 ; i < (1 << n); i++){
        Number tmp;
        for(j = 0; j < n; j++){
            if (i & (1 << j)){
                tmp = tmp * vals[j];
            }
        }
        for(j = 0; j < n; j++){
            int a = div_cnt(vals[j], tmp);
            add_dp[j][i] = a;
        }
    }
    for(i = 0; i < (1 << n); i++){
        for(i1 = 0; i1 < (int)submasks[i].size(); i1++){
            maski = submasks[i][i1];
            if (dp[i][maski] == INF){
                continue;
            }
            for(j = 0; j < (1 << n); j++){
                k = i | j;
                for(j1 = 0; j1 < (int)submasks[j].size(); j1++){
                    maskj = submasks[j][j1];
                    if (maski & maskj){
                        continue;
                    }
                    maskk = maski | maskj;
                    dp[k][maskk] = min(dp[k][maskk], dp[i][maski] + dp[j][maskj]);
                }
            }
            for(j = 0; j < n; j++){
                if (i & (1 << j)){
                    continue;
                }
                dp[i | (1 << j)][1 << j] = min(dp[i | (1 << j)][1 << j], dp[i][maski] + add_dp[j][maski] + 1);
            }
        }
    }
    int ans = INF;
    for(i = 0; i < (1 << n); i++){
        int val = dp[(1 << n) - 1][i];
        int fl = 0;
        for(j = 0; j < n; j++){
            if (i == (1 << j)){
                fl = 1;
            }
        }
        if (fl == 0){
            val++;
        }
        ans = min(val, ans);
    }
    cout << ans;
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}