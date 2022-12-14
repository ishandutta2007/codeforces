#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef long double db;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<db,db>pdd;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=2e5+10,M=500;
const ll mod=1e9+7;
const db eps=1e-8;
int sgn(db a){return a<-eps?-1:(a<eps?0:1);}

ll x[N],ar[N],n,id[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ar[i];
    iota(id+1,id+1+n,1);
    sort(id+1,id+1+n,[&](int a,int b){
        return ar[a]>ar[b];
    });
    int l=0,r=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=ar[id[i]]*((i+1)/2);
        if(i%2)x[id[i]]=--l;
        else x[id[i]]=++r;
    }
    cout<<ans*2<<endl;
    for(int i=0;i<=n;i++)cout<<x[i]<<' ';
    cout<<endl;
}
int main(){
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        solve();
    }
}