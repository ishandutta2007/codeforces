#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        int lo = 0;
        if(n % 3 == 0) lo = 1;
        for(int i = lo; i < n; i += 3) {
            for(int j = 0; j < m; ++j) {
                a[i][j] = 'X';
            }
        }
        for(int i = lo + 1; i < n; i += 3) {
            if(i + 1 == n) break;
            int f = 0;
            for(int j = 0; j < m; ++j) {
                if(a[i][j] == 'X' || a[i+1][j] == 'X') {
                    f = 1;
                    a[i][j] = a[i+1][j] = 'X';
                    break;
                }
            }
            if(f == 0) {
                a[i][0] = a[i+1][0] = 'X';
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0 ; j < m; ++j) cout << a[i][j];
            cout << endl;
        }
    }
}