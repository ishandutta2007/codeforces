#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
ll mod = 998244353;
ll t[MX];
int ans[MX];
int main() {
    int n; cin >> n;
    t[0] = 1;
    for(int i=1;i<=n;i++) {
        t[i] = t[i-1]*10%mod;
    }
    ans[n] = 10;
    for(int i=1;i<=n-1;i++) {
        //start or end
        ans[i]+=9*1LL*t[n-i-1]*2*10%mod;
        //mid
        if(n-i-2>=0) {
            ans[i]+=9*1LL*t[n-i-2]*1LL*9*10%mod*(n-i-1)%mod;
        }
    }
    for(int i=1;i<=n;i++) cout << (ans[i]+mod)%mod << "\n";
}