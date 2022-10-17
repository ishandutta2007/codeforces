#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    ll n;
    cin>>n;
    vector<ll> g;
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i==0) {
            g.push_back(i);
            if(i*i!=n) g.push_back(n/i);
        }
    }
    if(g.empty()) cout<<n<<endl;
    else {
        ll ans=g[0];
        for(ll i:g) ans=gcd(i,ans);
        cout<<ans<<endl;
    }
}