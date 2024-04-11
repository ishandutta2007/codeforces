#include<bits/stdc++.h>
typedef long long ll;
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

ll query(ll n,ll x,ll y)
{
    if(n%2==0)
    {
        if((x&1) == (y&1)) return (x-1)*n/2+(y-1)/2+1;
        return n*n/2+(x-1)*n/2+(y-1)/2+1;
    }
    if((x&1) == (y&1))
    {
        ll ans = 0;
        if((x-1)%2==0) ans += (x-1)/2 * n;
        else ans += (x-1)/2 * n + n/2 + 1;
        ans += (y+1) / 2;
        return ans;
    }
    ll ans = n*n/2+1;
    if((x-1)%2==0) ans += (x-1)/2 * n;
    else ans += (x-1)/2 * n + n/2 + 1;
    ans += y / 2;
    return ans;
}
int main()
{
    ll n,t;
    cin>>n>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<query(n,x,y)<<endl;
    }
}