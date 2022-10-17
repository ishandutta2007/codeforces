#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 200005;
const int mod = 998244353;
ll f[maxn],rf[maxn];
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
void init()
{
    f[0] = 1;
    for(int i=1;i<maxn;++i) f[i]=f[i-1]*i%mod;
    rf[maxn-1] = fpow(f[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i) rf[i]=rf[i+1]*(i+1)%mod;
}
ll comb(ll n,ll k){if(n<k)return 0;return f[n]*rf[k]%mod*rf[n-k]%mod;}
ll w[maxn<<2];
void ntt(ll a[],int n,int f=0)
{
    for(ll i=0,j=0;i<n;++i) {
        if(i>j) swap(a[i],a[j]);
        for(int l=n>>1;(j^=l)<l;l>>=1);
    }
    w[0]=1;
    for(int l=2;l<=n;l<<=1) {
        ll g=fpow(3,(mod-1)/l);
        if(f) g=fpow(g,mod-2);
        for(int j=(l>>1);j>=0;j-=2) w[j]=w[j>>1];
        for(int j=1;j<(l>>1);j+=2) w[j]=w[j-1]*g%mod;
        int m=l/2;
        for(ll*p=a;p!=a+n;p+=l) {
            for(int i=0;i<m;++i) {
                ll tmp=w[i]*p[i+m]%mod;
                p[i+m]=(p[i]-tmp+mod)%mod,p[i]=(p[i]+tmp)%mod;
            }
        }
    }
    if(f)
    {
        ll inv=fpow(n,mod-2);
        for(int i=0;i<n;++i) a[i]=a[i]*inv%mod;
    }
}
ll a[maxn<<2],b[maxn<<2];
int main()
{
    init();
    ll n,k;
    cin>>n>>k;
    if(n<=k) return cout<<0<<endl,0;
    if(k==0) return cout<<f[n]<<endl,0;
    int m=n-k;
    int len=1;for(;len<=2*m;len<<=1);
    for(int i=0;i<=m;++i) a[i]=(fpow(-1,i)*rf[i]%mod+mod)%mod,b[i]=fpow(i,n)*rf[i]%mod;
    ntt(a,len);ntt(b,len);
    for(int i=0;i<len;++i) a[i]=a[i]*b[i]%mod;
    ntt(a,len,1);
    cout << 2 * comb(n,n-k) * a[m] % mod * f[n-k] % mod << endl;
}