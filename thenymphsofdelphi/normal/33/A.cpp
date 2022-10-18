#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, x, y, ans = 0;
    cin >> n >> m >> k;
    int a[m];
    for (int i = 0; i < m; i++){
        a[i] = 1e7;
    }
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        x--;
        a[x] = min(a[x], y);
    }
    for (int i = 0; i < m; i++){
        if (a[i] != 1e7){
            ans += a[i];
        }
    }
    cout << min(ans, k);
}