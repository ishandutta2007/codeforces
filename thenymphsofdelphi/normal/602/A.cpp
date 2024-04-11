#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a = 0, b = 0, n, m, x, y, u;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        a *= x;
        cin >> u;
        a += u;
    }
    cin >> m >> y;
    for (int i = 0; i < m; i++){
        b *= y;
        cin >> u;
        b += u;
    }
    if (a < b){
        cout << '<';
    }
    else if (a > b){
        cout << '>';
    }
    else{
        cout << '=';
    }
}