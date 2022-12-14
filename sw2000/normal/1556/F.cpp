#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a, b, c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=14;
const ll mod=1e9+7;

int n;
ll p[N][N],ar[N],f[1<<N];
ll pm(ll a,ll b){
    ll ret=1;
    for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)ret=ret*a%mod;
    return ret;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)cin>>ar[i];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        p[i][j]=ar[i]*pm(ar[i]+ar[j],mod-2)%mod;
    }
    for(int s=1;s<1<<n;s++){
        f[s]=1;
        ll sub=0;
        for(int t=s-1&s;t;t=t-1&s){
            ll a=f[t];
            for(int i=0;i<n;i++)if(t&1<<i){
                for(int j=0;j<n;j++)if((t&1<<j)==0&&s&1<<j){
                    a=a*p[i][j]%mod;
                }
            }
            sub=(sub+a)%mod;
        }
        f[s]=(f[s]-sub+mod)%mod;
    }
    ll ans=0;
    for(int s=0;s<1<<n;s++){
        ll cnt=0,add=f[s];
        for(int i=0;i<n;i++)if(s&1<<i){
            cnt++;
            for(int j=0;j<n;j++)if((s&1<<j)==0){
                add=add*p[i][j]%mod;
            }
        }
        add=add*cnt%mod;
        ans=(ans+add)%mod;
    }
    cout<<ans;
}