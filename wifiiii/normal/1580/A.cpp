#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n+1, vector<int>(m+1));
        for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for(int j = 0; j < m; ++j) {
                a[i+1][j+1] = s[j] - '0';
            }
        }
        int ans = 1e9;
        for(int i = 1; i <= n; ++i) {
            vector<int> b(m + 1), e(m + 1);
            for(int j = 1; j <= m; ++j) if(a[i][j] == 0) b[j] = b[j-1] + 1; else b[j] = b[j-1];
            for(int j = i + 1; j < n; ++j) {
                vector<int> c(m + 1), d(m + 1);
                for(int k = 1; k <= m; ++k) {
                    if(a[j][k] == 1) c[k] = c[k-1] + 1; else c[k] = c[k-1];
                    if(a[j+1][k] == 0) d[k] = d[k-1] + 1; else d[k] = d[k-1];
                    e[k] += c[k];
                    b[k] += c[k];
                }
                for(int k = 1; k <= m; ++k) d[k] += b[k];
                if(j - i >= 3) {
                    int mn = 1e9;
                    for(int k = 4; k <= m; ++k) {
                        if(k >= 4) mn = min(mn, -d[k-3]-e[k-3]+e[k-4]);
                        ans = min(ans, 2*(j-i)-e[k]+e[k-1]+d[k-1]+mn);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}