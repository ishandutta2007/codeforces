#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        --r, --c;
        vector a(n, vector<char>(m));
        int b = 0, qwq = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
                b += a[i][j] == 'B';
                if(i == r || j == c) qwq += a[i][j] == 'B';
            }
        }

        if(a[r][c] == 'B') {
            cout << 0 << '\n';
        } else if(b == 0) {
            cout << -1 << '\n';
        } else if(qwq) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}