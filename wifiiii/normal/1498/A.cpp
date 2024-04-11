#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll sum(ll x) {
    int ret=0;
    while(x) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        while(gcd(x, sum(x)) == 1) ++x;
        cout << x << endl;
    }
}