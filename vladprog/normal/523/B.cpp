#include<bits/stdc++.h>

#define d(x) ((double)x)
#define ll long long

using namespace std;

int main ()
{
    ll n,t;
    double c;
    cin>>n>>t>>c;
    ll s[n+1];
    double real[n+1],approx[n+1],error[n+1];
    s[0]=0;
    approx[0]=0;
    for(ll i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        s[i]=s[i-1]+a;
        approx[i]=(approx[i-1]+d(a)/t)/c;
        if(i<t)
            continue;
        real[i]=d(s[i]-s[i-t])/t;
        error[i]=abs(approx[i]-real[i])/real[i];
    }
    ll m;
    cin>>m;
    for(ll i=1;i<=m;i++)
    {
        ll p;
        cin>>p;
        cout<<real[p]<<' '<<approx[p]<<' '<<error[p]<<endl;
    }
}