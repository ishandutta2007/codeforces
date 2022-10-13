#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 1e6+5;


int dp[1<<20];
int t[MX];
ll mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        ++dp[x];
    }
    //super set;
    for(int i=0;i<20;i++) {
        for(int msk=(1<<20)-1;msk>=0;msk--) {
            if((msk&(1<<i))==0) dp[msk]+=dp[msk^(1<<i)];
        }
    }
    t[0] =1;
    for(int i=1;i<=MX;i++) {
        t[i] = t[i-1]*2;
        if(t[i]>=mod) t[i]-=mod;
    }
    ll ans = 0;
    for(int msk=0;msk<1<<20;msk++) {
        int cnt = 0;
        for(int j=0;j<20;j++) if(msk&(1<<j)) ++cnt;
        if(cnt%2==0) ans+=t[dp[msk]];
        else ans-=t[dp[msk]];
        ans%=mod;
    }
    ans = (ans+mod)%mod;
    cout << ans;
}