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
const int N=2e7+10,M=500;
const ll mod=1e9+7;
const db eps=1e-8;
int sgn(db a){return a<-eps?-1:(a<eps?0:1);}

vi prm;
bitset<N>vis;
void prepare(){
    for(int i=2;i<N;i++){
        if(!vis[i])prm.push_back(i);
        for(auto j:prm)if(i*j>=N)break;else{
            vis[i*j]=1;
            if(i%j==0){
                break;
            }
        }
    }
}
int n;
ll cnt[N],f[N];
int main(){
    freopen("A.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    prepare();
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        cnt[a]++;
    }
    for(auto i:prm){
        for(int j=N/i*i;j;j-=i){
            cnt[j/i]+=cnt[j];
        }
    }
    f[1]=n;
    for(int i=1;i<N;i++){
        for(auto j:prm){
            if(i*j>=N)break;
            Max(f[j*i],f[i]+cnt[j*i]*(j*i-i));
        }
    }
    ll ans=0;
    for(int i=0;i<N;i++)Max(ans,f[i]);
    cout<<ans;
}