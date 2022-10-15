#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std; 
 
 
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n+1, vector<int>(m+1));
    vector<int> row(n+1);
    vector<int> col(m+1);
    for(int i=1; i<=n; i++) row[i] = i;
    for(int i=1; i<=m; i++) col[i] = i;
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> v[i][j];
        }
    }
 
    char s;
    for(int i=0, a, x, y; i<k; i++){
        cin >> s >> x >> y;
        if(s=='g'){
            cout << v[row[x]][col[y]] << "\n";
        }else if(s=='c'){
            swap(col[x], col[y]);
        }else{
            swap(row[x], row[y]);
        }
    }
}
 
int main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL), cout.tie(NULL);    
 
    int t=1;
 
    while(t--){
        solve();
    }
}