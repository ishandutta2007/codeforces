#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int mod = 998244353;
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
int main()
{
    ll n,m,l,r;
    cin>>n>>m>>l>>r;
    if(n%2 && m%2) return cout<<fpow(r-l+1,n*m)<<endl,0;
    n=n*m;
    ll a=r/2-(l-1)/2,b=r-l+1-a;
    cout << (fpow((a+b)%mod, n) + fpow(a-b, n)) * ((mod+1)/2) % mod << endl;
}