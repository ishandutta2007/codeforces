#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int m; cin >> m;
        string grid[n];
        for(int i = 0; i < n; i++)
            cin >> grid[i];
        bool work = true;
        bool rz = false, rp = false, wz = false, wp = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != '.') {
                    if((i + j) % 2) {
                        if(grid[i][j] == 'R') rp = true;
                        else wp = true;
                    }
                    else {
                        if(grid[i][j] == 'R') rz = true;
                        else wz = true;
                    }
                }
            }
        }
        if((rz && rp) || (wz && wp) || (rz && wz) || (rp && wp)) {
            work = false;
        }
        if(!work) {
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(rz || wp) {
                    if((i + j) % 2 == 0) grid[i][j] = 'R';
                    else grid[i][j] = 'W';
                }
                else {
                    if((i + j) % 2 == 0) grid[i][j] = 'W';
                    else grid[i][j] = 'R';
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << grid[i] << "\n";
        }
    }
}