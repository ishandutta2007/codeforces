#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a, b, c, mx;
    cin >> a >> b >> c;
    mx = max(a, b);
    mx = max(mx, c);
    if (mx >= 2 * (a + b + c - mx)){
        cout << a + b + c - mx;
    }
    else{
        cout << (a + b + c) / 3;
    }
}