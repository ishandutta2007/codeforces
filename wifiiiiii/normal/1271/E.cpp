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
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll n,k;
ll g(ll x)
{
    if(x&1)
    {
        ll ret = 0, r = 1;
        while(1)
        {
            
            if(x > n) return ret;
            if(x + r > n) return ret + n - x + 1;
            ret += r;
            x = x * 2;
            r <<= 1;
        }
    }
    ll ret = 0, r = 2;
    while(1)
    {
        if(x > n) return ret;
        if(x + r > n) return ret + n - x + 1;
        ret += r;
        r <<= 1;
        x = x * 2;
    }
    return 0;
}
int main()
{
    cin>>n>>k;
    ll ans1=0,ans2=0;
    ll lo=0,hi=n/2;
    while(lo<hi)
    {
        ll mid=(lo+hi+1)/2;
        if(g(2*mid)>=k) lo=mid;
        else hi=mid-1;
    }
    ans1=lo*2;
    lo=0,hi=(n-1)/2;
    while(lo<hi)
    {
        ll mid=(lo+hi+1)/2;
        if(g(2*mid+1)>=k) lo=mid;
        else hi=mid-1;
    }
    ans2=lo*2+1;
    cout<<max(ans1,ans2)<<endl;
}