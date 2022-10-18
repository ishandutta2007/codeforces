#pragma optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    map<ll,ll> m;
    for(ll i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        m[t]++;
    }
    ll l=1e18,r=-1e18;
    for(auto t:m)
        l=min(l,t.first),
        r=max(r,t.first);
    for(ll i=l;i<=r;i++)
        m[i];
    vector< pair<ll,ll> > v(m.begin(),m.end());
    if(v.size()<=2)
    {
        cout<<n<<"\n";
        for(auto t:v)
            for(ll j=0;j<t.second;j++)
                cout<<t.first<<" ";
        exit(0);
    }
    ll s=0;
    for(auto t:v)
        s+=t.first*t.second;
    ll ans=n+1,x,y,z;
    for(ll ty=0;ty<=n;ty++)
    {
        ll ts=s-ty*v[1].first,
           tx2=(n-ty)*(v[1].first+1)-ts;
        if(tx2%2==0)
        {
            ll tx=tx2/2,tz=n-tx-ty;
            if(tx<0||tz<0)
                continue;
            ll res=min(tx,v[0].second)+
                   min(ty,v[1].second)+
                   min(tz,v[2].second);
            if(res<ans)
                ans=res,
                x=tx,
                y=ty,
                z=tz;
        }
    }
    cout<<ans<<"\n";
    //cout<<x<<" "<<y<<" "<<z<<"\n";
    for(ll i=0;i<x;i++)
        cout<<v[0].first<<" ";
    for(ll i=0;i<y;i++)
        cout<<v[1].first<<" ";
    for(ll i=0;i<z;i++)
        cout<<v[2].first<<" ";
}