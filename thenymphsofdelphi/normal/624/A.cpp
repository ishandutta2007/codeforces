#include<bits/stdc++.h>
using namespace std;

int main(){
    int d, l, v1, v2;
    cin >> d >> l >> v1 >> v2;
    long double ans = 1.0 * (l - d) / (v1 + v2);
    cout << fixed << setprecision(6) << ans;
}