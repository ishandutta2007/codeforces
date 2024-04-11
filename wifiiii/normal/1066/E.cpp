#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int mod = 998244353;
ll pw[200005];
int main() {
    pw[0]=1;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) pw[i]=pw[i-1]*2%mod;
    string s,t;
    cin>>s>>t;
    reverse(all(s));
    reverse(all(t));
    vector<int> sum(t.size()+1);
    for(int i=0;i<t.size();++i) sum[i+1]=sum[i]+(t[i]=='1');
    int tot=sum[t.size()];
    ll ans=0;
    for(int i=0;i<s.size();++i) {
        if(i>t.size()) break;
        if(s[i]=='1') ans+=pw[i]*(tot-sum[i])%mod;
    }
    ans%=mod;
    cout<<ans<<endl;
}