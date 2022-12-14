#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
//
void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}

int main()
{
    ll w,v,p,n;
    cin>>n>>p>>w>>v;
    ll gcd=__gcd(w,v);
    ll mod=w/gcd;
    if(p%gcd)
    {
        cout<<-1;
        return 0;
    }
    ll x,y,z;
    exgcd(w,v,x,y);
    y=(p%w/gcd*y)%mod;
    if(y<0)y+=mod;
    x=(p-y*v)/w;
    z=n-x-y;
    if(x>=0&&z>=0)
    {
        cout<<x<<' '<<y<<' '<<z;
    }
    else cout<<-1;
    return 0;
}