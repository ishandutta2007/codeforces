#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m, x;
    cin >> n >> m >> x;
    x--;
    int r = m * 2;
    cout << x / r + 1 << ' ';
    x %= r;
    cout << x / 2 + 1 << ' ';
    x %= 2;
    if (x == 0){
        cout << 'L';
    }
    else{
        cout << 'R';
    }
}