#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int b[m];
    for(int i=0;i<m;i++)
        cin >> b[i];
    int grid[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            grid[i][j] = 0;
    int x =  0;
    int y = 0;
    for(int i=0;i<n-1;i++)
        grid[i][m-1] = a[i];
    for(int i=0;i<m-1;i++)
        grid[n-1][i] = b[i];
    for(int i=0;i<n;i++)
        x^=a[i];
    for(int i=0;i<m;i++)
        y^=b[i];
    if(x!=y){
        cout << "NO" << endl;
        return 0;
    }
    x^=a[n-1];
    x^=b[m-1];
    cout << "YES" << endl;
    grid[n-1][m-1] = x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

}