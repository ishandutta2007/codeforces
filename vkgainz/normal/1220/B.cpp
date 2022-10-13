#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n; cin >> n;
    ll grid[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> grid[i][j];
    ll a[n];
    for(int i=0;i<n-2;i++)
        a[i+1] = (grid[i][i+1]*grid[i+1][i+2])/(grid[i][i+2]);
    for(int i=1;i<n-1;i++) a[i] = sqrt(a[i]);
     a[0] = grid[0][1]/a[1];
     a[n-1] = grid[n-1][n-2]/a[n-2];
     for(int i=0;i<n;i++) cout << a[i] << endl;
        
}