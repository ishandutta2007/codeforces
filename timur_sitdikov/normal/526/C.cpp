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

ll calc(ll c, ll wa, ll wb, ll ha, ll hb){
    ll lim = 1e6, ans = 0ll;
    for(ll i = 0; i <= lim; i++){
        if (i * wa > c){
            break;
        }
        ll j = (c - i * wa) / wb;
        ans = max(ans, i * ha + j * hb);
    }
    return ans;
}

void solve(){
    ll c, wa, wb, ha, hb;
    cin >> c >> ha >> hb >> wa >> wb;
    cout << max(calc(c, wa, wb, ha, hb), calc(c, wb, wa, hb, ha)) << endl;  
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