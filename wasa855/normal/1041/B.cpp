#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll x,ll y)
{
    if(x>y)
    {
        swap(x,y);
    }
    if(x==0)
    {
        return y;
    }
    return gcd(x,y%x);
}
int main()
{
    ll a,b,m,n;
    cin>>a>>b>>n>>m;
    ll t=gcd(n,m);
    n/=t;
    m/=t;
    ll x=a/n;
    ll y=b/m;
    cout<<min(x,y)<<endl;
    return 0;
}
///aedlitjhsoirunhyoigfsuhoiyxfcdg