#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

int main()
{
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll t,s,x,c;
        cin>>t>>s>>x>>c;
        if(t>=s)
            ans+=c+x*m;
        else
        {
            ll d=s-t;
            if(d>=m)
                ans+=c;
            else
            {
                ll t=(m+d-1)/d;
                ans+=min({x*m+c,t*c,(t-1)*(c-d*x)+x*(d+m)});
            }
        }
    }
    cout<<ans;
}