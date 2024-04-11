#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

map<pair<int,int>, int> mp;
// (position, prime) -> cnt
multiset<int> s[200005];
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
const int mod = 1e9+7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r%mod;}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    ll ans=0;
    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;
        ans=gcd(ans,x);
        for(int j=2;j*j<=x;++j) {
            if(x%j==0) {
                int cnt=0;
                while(x%j==0) ++cnt,x/=j;
                mp[{i,j}]=cnt;
                s[j].insert(cnt);
            }
        }
        if(x>1) mp[{i,x}]=1,s[x].insert(1);
    }
    while(q--) {
        int p,x;
        cin>>p>>x;
        for(int j=2;j*j<=x;++j) {
            if(x%j==0) {
                int cnt=0;
                while(x%j==0) ++cnt,x/=j;
                int l=0;
                if(s[j].size()==n) l=*s[j].begin();
                if(mp.count({p,j})) {
                    s[j].erase(s[j].find(mp[{p,j}]));
                }
                mp[{p,j}]+=cnt;
                s[j].insert(mp[{p,j}]);
                int r=0;
                if(s[j].size()==n) r=*s[j].begin();
                for(int i=l;i<r;++i) ans=ans*j%mod;
            }
        }
        if(x>1) {
            int l=0;
            if(s[x].size()==n) l=*s[x].begin();
            if(mp.count({p,x})) {
                s[x].erase(s[x].find(mp[{p,x}]));
            }
            mp[{p,x}]++;
            s[x].insert(mp[{p,x}]);
            int r=0;
            if(s[x].size()==n) r=*s[x].begin();
            for(int i=l;i<r;++i) ans=ans*x%mod;
        }
        cout<<ans<<'\n';
    }
}