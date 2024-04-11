#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

void solve() {
    int n; cin >> n;
    array<vector<int>, 2> v;
    
    for (int i = 0; i < n; ++i) {
        int x; cin >>x;
        v[x % 2].push_back(x);
    }
    
    cout << (is_sorted(v[0].begin(),v[0].end()) && is_sorted(v[1].begin(), v[1].end()) ?  "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}