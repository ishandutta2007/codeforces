#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int f = 2 * c + d, g = d + 3 * e;
    cout << max(0LL, f - a) + max(0LL, g - b);
}