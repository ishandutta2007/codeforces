#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m, dif;
    cin >> n >> m;
    if (!(n - 1 <= m && m <= 2 * (n + 1))){
        cout << -1;
        return 0;
    }
    if (n >= m){
        for (int i = 0; i < m; i++){
            cout << "01";
        }
        if (n > m){
            cout << '0';
        }
        return 0;
    }
    dif = m - n - 1;
    for (int i = 0; i < n; i++){
        cout << 1;
        if (dif){
            cout << 1;
            dif--;
        }
        cout << 0;
    }
    cout << 1;
    if (dif){
        cout << 1;
    }
    return 0;
}