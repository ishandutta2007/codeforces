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

int a[200005],ans[200005];
const int maxn = 200005;
int bit[maxn];
void add(int x,int v){for(;x<maxn;x+=x&-x)bit[x]+=v;}
int sum(int x) {int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    vi v;ii v.pb(a[i]);sort(all(v));v.resize(unique(all(v))-v.begin());
    ii a[i]=lower_bound(all(v),a[i])-v.begin()+1;
    ii add(a[i],1);
    ii ans[i]=sum(a[i]-1);
    for(int i=1;i<=m;++i) {
        int u,v;
        cin>>u>>v;
        if(a[u]>a[v]) {
            --ans[u];
        } else if(a[u]<a[v]) {
            --ans[v];
        }
    }
    ii cout<<ans[i]<<" ";cout<<endl;
}