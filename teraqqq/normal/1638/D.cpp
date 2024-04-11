#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using pi = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;
    vector v(n, vector<int>(m));
    vector was(n, vector<int>(m));
    vector<array<int, 3>> ans;
    for (auto& u : v) for(int& x : u) cin >>x;
    
    queue<pi> q;
    
    auto check = [&](int i, int j) {
        if (i < 0 || i > n - 2 || j < 0 || j > m - 2) return;
        if (was[i][j]) return;
        
        
        auto see = [&](int y, int x) {
            return y == -1 || y == x;
        };
        
        const int x = max({ v[i][j],v[i+1][j],v[i][j+1],v[i+1][j+1]});
        
        if (see(v[i][j], x) && see(v[i+1][j], x) && see(v[i][j+1], x) && see(v[i+1][j+1], x)) {
            was[i][j] = true;
            q.emplace(i, j);
        }
    };
    
    for (int i = 0; i < n-1; ++i)
    for (int j = 0; j < m-1; ++j)
        check(i,j);
    
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        const int x = max({ v[i][j],v[i+1][j],v[i][j+1],v[i+1][j+1]});
        if (x < 0) continue;
        
        ans.push_back(array{i+1, j+1, x});
        v[i][j]=v[i+1][j]=v[i][j+1]=v[i+1][j+1]=-1;
        check(i-1,j-1);
        check(i-1,j);
        check(i-1,j+1);
        check(i,j-1);
        check(i,j+1);
        check(i+1,j-1);
        check(i+1,j);
        check(i+1,j+1);
    }
    
    reverse(ans.begin(), ans.end());
    
    bool ok = true;
    for (auto& u : v) for(int&x:u) if(x >= 0) ok = false;
    
    if (ok) {
        cout << size(ans) << '\n';
        for (auto [x, y, c] : ans){
            cout << x << " " << y << " " << c << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}