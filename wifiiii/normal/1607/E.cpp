#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int x = 0, y = 0;
        string s;
        cin >> s;
        int xr = 0, xl = 0, yr = 0, yl = 0, ax = 0, ay = 0;
        for(char c : s) {
            if(c == 'U') --x;
            if(c == 'D') ++x;
            if(c == 'L') --y;
            if(c == 'R') ++y;
            xr = max(xr, x);
            xl = min(xl, x);
            yr = max(yr, y);
            yl = min(yl, y);
            if(xr - xl >= n || yr - yl >= m) break;
            ax = n - 1 - xr;
            ay = m - 1 - yr;
        }
        cout << ax + 1 << " " << ay + 1 << endl;
    }
}