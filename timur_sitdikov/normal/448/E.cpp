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

ll d[1000000], d1[1000000];
int top_d, top_d1;

vector<int> divs[100005];

map<ll, int> ind;

ll ans[1000000];
int top_ans;

void rec_sol(int pos, int level, int k){
    if (top_ans >= 100000){
        return;
    }
    int i;
    if (level == k || pos == 0){
        /*for(i = 0; i < (int)divs[pos].size(); i++){
            ans[top_ans++] = d[divs[pos][i]];
            if (top_ans == 100000){
                return;
            }
        }*/
        ans[top_ans++] = d[pos];
        return;
    }
    for(i = 0; i < (int)divs[pos].size(); i++){
        if (top_ans >= 100000){
            return;
        }
        rec_sol(divs[pos][i], level + 1, k);
    }
}

void solve(){
    ll v, i, j, k;
    cin >> v >> k;
    k = min(k, (ll)(1e5 + 5));
    for(i = 1; i * i <= v; i++){
        if (v % i == 0){
            d[top_d] = i;
            if (i * i != v){
                d1[top_d1] = v / i;
                top_d1++;
            }
            top_d++;
        }
    }
    for(i = top_d1 - 1; i >= 0; i--){
        d[top_d++] = d1[i];
    }
    for(i = 0; i < top_d; i++){
        ind[d[i]] = i;
    }
    for(i = 0; i < top_d; i++){
        for(j = 0; j <= i; j++){
            if (d[i] % d[j] == 0){
                divs[i].pb(j);
            }
        }
    }
    rec_sol(top_d - 1, 0, k);
    for(i = 0; i < top_ans; i++){
        printf("%I64d ", ans[i]);
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