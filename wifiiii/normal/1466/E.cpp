#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int mod = 1e9+7;
ll a[500005];
int cnt[60][2];
void ins(ll x) {for(int i=59;i>=0;--i) cnt[i][x>>i&1]++;}
ll qry1(ll x) {
    ll ret=0;
    for(int i=59;i>=0;--i) {
        ll tmp=(1ll<<i)%mod;
        if(x>>i&1) ret+=tmp*cnt[i][1]%mod;
    }
    return ret%mod;
}
ll qry2(ll x) {
    ll ret=0;
    for(int i=59;i>=0;--i) {
        ll tmp=(1ll<<i)%mod;
        if(x>>i&1) ret+=tmp*(cnt[i][1]+cnt[i][0])%mod;
        else ret+=tmp*cnt[i][1]%mod;
    }
    return ret%mod;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        memset(cnt,0,sizeof(cnt));
        int n;
        cin>>n;
        ii cin>>a[i],ins(a[i]);
        ll ans=0;
        ii ans+=qry1(a[i])*qry2(a[i])%mod;
        cout<<ans%mod<<endl;
    }
}