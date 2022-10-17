#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll f = 1, ans = 0;
        for(int i = 2;; ++i) {
            if(f > n) break;
            ans += (n / f - n / lcm(f, i)) % mod * i % mod;
            f = lcm(f, i);
        }
        cout << ans % mod << endl;
    }
}