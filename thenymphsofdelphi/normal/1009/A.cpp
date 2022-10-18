#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y, cnt = 0;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    x = 0;
    y = 0;
    while (x < n && y < m){
        if (b[y] >= a[x]){
            x++;
            y++;
            cnt++;
        }
        else{
            x++;
        }
    }
    cout << cnt;
}