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

ll a[300005];
const int mod = 998244353;
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
int main()
{
    int n;
    cin>>n;
    a[0] = 1; a[1] = 18;
    for(int i=2;i<=n;++i) a[i]=(81*i+99)*fpow(10,i-2)%mod;
    ll ans=0;
    for(int i=n-1;i>=0;--i) cout<<10*a[i]%mod<<" ";cout<<endl;
}