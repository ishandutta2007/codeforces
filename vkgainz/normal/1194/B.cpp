#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
void solve(){
    int n,m;
    cin >> n >> m;
    int rowsum[n];
    int colsum[m];
    for(int i=0;i<n;i++) rowsum[i] = 0;
    for(int j=0;j<m;j++) colsum[j] = 0;
    char grid[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='*'){
                ++rowsum[i];
                ++colsum[j];
            }
        }
    }
    int least = 10000000;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp = n+m-rowsum[i]-colsum[j];
            if(grid[i][j]=='.') --temp;
            least = min(least,temp);
        }
    }
    cout << least << endl;
}
int main(){
    int q; cin >> q;
    while(q--) solve();
}