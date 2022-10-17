#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j < m; ++j) {
                if(a[i][j] == '*') {
                    int p = i;
                    while(p + 1 < n && a[p + 1][j] == '.') ++p;
                    swap(a[i][j], a[p][j]);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}