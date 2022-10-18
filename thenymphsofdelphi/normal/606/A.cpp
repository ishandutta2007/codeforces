#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    int pos = max(0ll, a - x) / 2 + max(0ll, b - y) / 2 + max(0ll, c - z) / 2;
    int neg = max(0ll, x - a) + max(0ll, y - b) + max(0ll, z - c);
    if (pos >= neg){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}