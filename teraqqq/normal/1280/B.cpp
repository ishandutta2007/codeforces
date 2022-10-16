#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define rsz resize

using namespace std;
using ll = long long;
using ld = double;
using vi = vector<int>;
using pi = pair<int, int>;

mt19937 rng;

const ll MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    int k  = 0;
    for(auto& v : s) {
        cin >> v;
        for(char c : v) k += c == 'A';
    }

    if(k == 0) { cout << "MORTAL" << endl; return; }
    if(k == n*m) { cout << 0 << endl; return; }

    int can;
    can = 1; for(int i = 0; i < m; ++i) if(s[0][i]   != 'A') can = 0; if(can) { cout << 1 << endl; return; }
    can = 1; for(int i = 0; i < m; ++i) if(s[n-1][i] != 'A') can = 0; if(can) { cout << 1 << endl; return; }
    can = 1; for(int i = 0; i < n; ++i) if(s[i][0]   != 'A') can = 0; if(can) { cout << 1 << endl; return; }
    can = 1; for(int i = 0; i < n; ++i) if(s[i][m-1] != 'A') can = 0; if(can) { cout << 1 << endl; return; }
    if(s[0][0] == 'A' || s[0][m-1] == 'A' || s[n-1][m-1] == 'A' || s[n-1][0] == 'A') { cout << 2 << endl; return; }
    for(int  i = 0; i < n; ++i) {
        can = 1;
        for(int j = 0; j < m; ++j) if(s[i][j]   != 'A') can = 0;
        if(can) { cout << 2 << endl; return; }
    }
    for(int  i = 0; i < m; ++i) {
        can = 1;
        for(int j = 0; j < n; ++j) if(s[j][i]   != 'A') can = 0;
        if(can) { cout << 2 << endl; return; }
    }
    for(int i = 0; i < n; ++i) if(s[i][0] == 'A' || s[i][m-1] == 'A') { cout << 3 << endl; return; }
    for(int i = 0; i < m; ++i) if(s[0][i] == 'A' || s[n-1][i] == 'A') { cout << 3 << endl; return; }
    cout << 4 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t; while(t--) solve();
}