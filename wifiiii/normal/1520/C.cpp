#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 2) {
            cout << -1 << '\n';
            continue;
        }
        if(n == 3) {
            cout << "2 9 7\n"
                    "4 6 3\n"
                    "1 8 5\n";
            continue;
        }
        vector<vector<int>> a(n, vector<int>(n));
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; j += 2) {
                a[i][j] = ++cnt;
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < n; j += 2) {
                a[i][j] = ++cnt;
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
}