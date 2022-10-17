#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5+5;
const int mod = 1e9+7;
ll f[maxn];
int main() {
    for(int i=1;i<=10;++i) f[i]=1;
    for(int i=11;i<maxn;++i) f[i]=(f[i-9]+f[i-10])%mod;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        int n;
        cin >> s >> n;
        ll ans = 0;
        for(char c : s) ans += f[c - '0' + n + 1];
        cout << ans % mod << endl;
    }
}