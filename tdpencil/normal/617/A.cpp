#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll a;
    cin >> a;
    ll ans =0;
    if(a%5==0) ans=a/5;
    else ans=a/5+1;
    cout << ans;
}