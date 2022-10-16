#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n+1, vector<int>(n+1, 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            matrix[i][j] = c == '0' ? 0 : 1;
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1 && matrix[i][j+1] == 0 && matrix[i+1][j] == 0){
                ok = false;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}