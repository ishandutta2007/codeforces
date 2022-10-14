#include <bits/stdc++.h>
using namespace std;

void solve(int test_case = 0) {
    int n, m;
    cin >> n >> m;
    for(int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
    }

    string s;
    for(int i = 0; i < n; i++) {
        if(i&1)
            s += '1';
        else
            s += '0';
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;

    // cin >> T;
    //

    while(T--) {
        solve();
    }
    
}