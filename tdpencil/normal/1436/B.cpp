#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define pb push_back
int main() {
    ll a;
    cin >> a;
    for(int x =0; x < a;x ++) {
        int u;
        cin >> u;
        vector<vector<int>> matrix;
        vector<int> b;
        b.pb(1);
        b.pb(1);
        for(int i =0 ; i < u-2; i++) {
            b.pb(0);
        }
        for(int i =0; i < u; i++) {
            matrix.pb(b);
            rotate(b.begin(), b.begin()+1, b.end());
        }
        for(int i =0; i < u; i++) {
            for(int j = 0; j < u; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << '\n';
        }
        
        
        
        
        
        
        // Have a vector of 2 2 and then add 0
    }
}