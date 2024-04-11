#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a, b;
    cin >> a >> b;
    cout << fixed << setprecision(6);
    long double ans = pow(1.000000011, b);
    ans *= a;
    cout << ans;
}