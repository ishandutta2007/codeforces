#include<bits/stdc++.h>
using namespace std;

int main(){
    long double n, p, q, t, ans;
    cin >> n >> p >> q;
    t = p + q;
    ans = n / t * p;
    cout << fixed << setprecision(4) << ans;
}