#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t; 
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        int f[n][m];
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                cin >> f[a][b];
            }
        }
        int c0 = 0, c1 = 0;
        for (int a = 0; a < n; a++) {
            bool flag = 0;
            for (int b = 0; b < m; b++) {
                if (f[a][b]) flag = 1; 
            }
            if (!flag) c0++;
        }
        for (int b = 0; b < m; b++) {
            bool flag = 0;
            for (int a = 0; a < n; a++) {
                if (f[a][b]) flag = 1; 
            }
            if (!flag) c1++;
        }
        int x = min(c1, c0);
        if (x % 2 == 0) {
            cout << "Vivek" << endl;
        } else {
            cout << "Ashish" << endl;
        }
    }
}