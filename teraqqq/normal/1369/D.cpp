#include <bits/stdc++.h>

const int M = 1e9+7;

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    const int n = 2e6+7;
    vector<ll> a(n); a[3] = 4;
    for(int i = 4; i < n; a[i++] %= M) {
        if(i%3) a[i] = 2*a[i-2] + a[i-1];
        else    a[i] = 4*a[i-4] + 4*a[i-3] + a[i-2] + 4;
    }
    
    int t, x;
    for(cin >> t; t--; ) 
        cin >> x, cout << a[x] << '\n'; 
}