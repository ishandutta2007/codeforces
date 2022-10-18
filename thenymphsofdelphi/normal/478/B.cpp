#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int m, n, mn, mx, p, q;
    cin >> n >> m;
    p = n / m;
    q = n - p * m;
    mn = (p * (p - 1) / 2) * (m - q) + ((p + 1) * p / 2) * q;
    mx = (n - m + 1) * (n - m) / 2;
    cout << mn << " " << mx;
}