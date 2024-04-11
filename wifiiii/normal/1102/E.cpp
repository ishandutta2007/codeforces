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
typedef pair<int, int> pii;

const int mod=998244353;
int a[200005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> mp(200001);
    vii v;
    vi aa;
    ii cin>>a[i],aa.pb(a[i]);
    sort(all(aa));
    aa.resize(unique(all(aa))-aa.begin());
    ii a[i]=lower_bound(all(aa),a[i])-aa.begin()+1;
    for(int i=1;i<=n;++i) {
        int x=a[i];
        if(mp[x]) v.push_back({mp[x],i});
        else v.push_back({i,i});
        mp[x]=i;
    }
    sort(all(v),[&](pii i,pii j){return i.first<j.first;});
    int mx=0,cnt=-1;
    for(int i=0;i<v.size();++i) {
        mx=max(mx,v[i].second);
        if(i+1<v.size() && mx>=v[i+1].first) {
            continue;
        } else {
            ++cnt;
            mx=0;
        }
    }
    ll ans=1;
    for(int i=1;i<=cnt;++i) ans=ans*2%mod;
    cout<<ans<<endl;
}