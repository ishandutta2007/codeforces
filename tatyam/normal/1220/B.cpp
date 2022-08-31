#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector a(n, vector<ll>(n));
    for(auto& v : a) for(ll& i : v) cin >> i;
    vector<ll> ans(n);
    ll xyz = 1;
    {
        const ll g = gcd(a[0][1], a[1][2]);
        a[0][1] /= g;
        a[1][2] /= g;
        xyz *= g;
    }
    {
        const ll g = gcd(a[0][1], a[2][0]);
        a[0][1] /= g;
        a[2][0] /= g;
        xyz *= g;
    }
    {
        const ll g = gcd(a[2][0], a[1][2]);
        a[2][0] /= g;
        a[1][2] /= g;
        xyz *= g;
    }
    xyz *= sqrt(a[0][1]);
    xyz *= sqrt(a[1][2]);
    xyz *= sqrt(a[2][0]);
    ans[0] = xyz / a[2][1];
    ans[1] = xyz / a[0][2];
    ans[2] = xyz / a[1][0];
    for(ll i = 3; i < n; i++) ans[i] = a[0][i] / ans[0];
    for(ll i : ans) cout << i << ' ';
}