#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional>
#include <string>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> num(n, vector<int>(m));
        bool work = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                if((i == 0 || i == n - 1) && (j == 0 || j == m - 1))
                    num[i][j] = 2;
                else if(i > 0 && i < n - 1 && j > 0 && j < m - 1) num[i][j] = 4;
                else num[i][j] = 3;
                work &= a[i][j] <= num[i][j];
            }
        }
        if(!work) cout << "NO" << "\n";
        else {
            cout << "YES" << "\n";
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << num[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
}