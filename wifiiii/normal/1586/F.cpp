#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[2005][2005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    int tot = 0;
    int m = 1;
    while(m <= n) {
        ++tot;
        int mm = m * k;
        for(int i = m + 1; i <= mm; i += m) {
            if(i > 2000) break;
            for(int p = i; p < i + m; ++p) {
                if(p > 2000) break;
                for(int q = p + 1; q < i + m; ++q) {
                    if(q > 2000) break;
                    a[p][q] = a[p - i + 1][q - i + 1];
                }
            }
        }
        for(int i = 1; i <= mm; ++i) {
            if(i > 2000) break;
            for(int j = i + 1; j <= mm; ++j) {
                if(j > 2000) break;
                if(a[i][j] == 0) a[i][j] = tot;
            }
        }
        m = mm;
    }
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            mx = max(mx, a[i][j]);
        }
    }
    cout << mx << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            cout << a[i][j] << " ";
        }
    }
    cout << endl;
}