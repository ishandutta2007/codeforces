#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 && y1 == y2) {
        cout << fpow(k, 1ll * n * m) << endl;
    } else {
        cout << fpow(k, 1ll * n * m - 1ll * r * c) << endl;
    }
}