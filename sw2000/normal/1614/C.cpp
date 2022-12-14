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
int d[N],two[N]{1};
int solve(){
    int n,m;cin>>n>>m;
    vector<array<int,3>>ar(m);
    for(auto &i:ar)for(auto &j:i)cin>>j;
    ll ret=0;
    for(int i=0;i<30;i++){
        for(int j=0;j<=n+1;j++)d[j]=0;
        for(auto j:ar){
            if((j[2]&1<<i)==0){
                d[j[0]]++;
                d[j[1]+1]--;
            }
        }
        ll cnt[2]{};
        for(int j=1;j<=n;j++){
            d[j]+=d[j-1];
            if(d[j]==0)cnt[1]++;
            else cnt[0]++;
        }
        if(cnt[1])ret+=1ll*two[n-1]*two[i]%mod;
    }
    return ret%mod;
}
int main(){
    for(int i=1;i<N;i++)two[i]=two[i-1]*2%mod;
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int _;cin>>_;
    while(_--){
        cout<<solve()<<endl;
    }
}