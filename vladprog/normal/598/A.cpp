#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll p[40];
    p[0]=1;
    for(ll i=1;i<40;i++)
        p[i]=p[i-1]*2;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=n*(n+1)/2;
        for(ll i=0;i<40;i++)
            if(p[i]>n)
            {
                ans-=p[i+1]-2;
                break;
            }
        cout<<ans<<"\n";
    }
}