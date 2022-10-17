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

const int maxn = 200005;
int a[maxn], b[maxn];
struct bit {
    int n;
    ll a[maxn];
    void init(int _n) {n = _n;}
    void add(int x, int v) {for(;x<=n;x+=x&-x) a[x]+=v;}
    ll sum(int x) {ll ret=0;for(;x;x-=x&-x)ret+=a[x];return ret;}
}b1, b2;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ii cin >> a[i];
    ii cin >> b[i];
    vector<int> v1, v2;
    ii v1.push_back(b[i]);
    sort(all(v1));sort(all(v2));
    v1.resize(unique(all(v1))-v1.begin());
    ii b[i]=lower_bound(all(v1),b[i])-v1.begin()+1;
    vector<int> ord(n);
    iota(all(ord),1);
    sort(all(ord),[&](int i,int j){return a[i]<a[j];});
    b1.init(n+1);b2.init(n+1);
    ll ans=0;
    for(int x:ord) {
        // a[x], b[x]
        if(b[x] >= 0) {
            ans += b1.sum(b[x])*a[x]-b2.sum(b[x]);
        }
        b1.add(b[x],1);
        b2.add(b[x],a[x]);
    }
    cout<<ans<<endl;
}