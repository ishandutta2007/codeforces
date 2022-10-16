#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int&x :p)cin >>x,--x;
    
    int k = 0;
    while (k < n && p[k] == k) ++k;
    
    if (k < n) {
        auto it = find(p.begin(), p.end(), k);
        reverse(p.begin()+k, ++it);
    }
    
    for (int x: p) cout <<x+1 << ' ';
    cout <<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}