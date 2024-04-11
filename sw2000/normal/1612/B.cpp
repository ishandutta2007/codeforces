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
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<long double,long double>pdd;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef long  double ld;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=5000+10,M=500;
const ll mod=1e9+7;

void solve(){
    int n,a,b;cin>>n>>a>>b;
    vi l{a},r{b};
    for(int i=1;i<a;i++)if(i!=b)r.push_back(i);
    for(int i=b+1;i<=n;i++)if(i!=a)l.push_back(i);
    if(r.size()>n/2||l.size()>n/2){
        cout<<-1;
        return;
    }
    for(int i=a+1;i<b;i++){
        if(l.size()<n/2)l.push_back(i);
        else r.push_back(i);
    }
    for(auto i:l)cout<<i<<' ';
    for(auto i:r)cout<<i<<' ';
}
int main(){
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        solve();
        cout<<endl;
    }
}