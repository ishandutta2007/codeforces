#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<int> x(q), y(q);
        for(int i = 0; i < q; ++i) cin >> x[i] >> y[i];
        map<int, int> vx, vy;
        int cnt = 0;
        for(int i = q - 1; i >= 0; --i) {
            if((vy.size() == m || vx[x[i]]) && (vx.size() == n || vy[y[i]])) continue;
            vx[x[i]] = vy[y[i]] = 1;
            cnt += 1;
        }
        cout << fpow(k, cnt) << '\n';
    }
}