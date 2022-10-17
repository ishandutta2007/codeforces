#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(gcd(i,n/i)==1)
            {
                ans=i;
            }
        }
    }
    cout<<ans<<" "<<n/ans<<endl;
}