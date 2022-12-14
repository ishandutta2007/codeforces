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

int two[N]{1};
int main(){
    for(int i=1;i<N;i++)two[i]=two[i-1]*2%mod;
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int n;cin>>n;
    ll ans=(two[n]-1+mod)%mod;
    vi ar(n);
    for(auto &i:ar)cin>>i;
    int tot[30]{};
    for(auto i:ar){
        int cnt=0;
        while(i%2==0){
            cnt++;i/=2;
        }
        tot[cnt]++;
    }
    for(int i=1;i<30;i++){
        int cnt=0;
        for(int j=i+1;j<30;j++)cnt+=tot[j];
        ans=(ans-1ll*two[tot[i]-1]*two[cnt]%mod+mod)%mod;
    }
    cout<<ans;
}