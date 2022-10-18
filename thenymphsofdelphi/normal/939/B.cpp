#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int k, n, mn = 1e18 + 1, x, ai, ad;
    cin >> k >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (k % x < mn){
            mn = k % x;
            ai = i;
            ad = k / x;
        }
    }
    cout << ai + 1 << ' ' << ad;
}