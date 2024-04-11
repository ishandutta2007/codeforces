#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a, b, c, d;
    cin >> a >> b >> c;
    d = a * b * c;
    d = sqrt(d);
    cout << 4 * ((d / a) + (d / b) + (d / c));
}