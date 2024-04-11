#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 1e9+7;
ll x,y;
string s;
int n;
int check(ll m)
{
    ll t=m/n;
    ll xx=0,yy=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='U') yy++;
        else if(s[i]=='D') yy--;
        else if(s[i]=='L') xx--;
        else xx++;
    }
    ll nx=xx*t,ny=yy*t;
    for(int i=0;i<m%n;++i)
    {
        if(s[i]=='U') ny++;
        else if(s[i]=='D') ny--;
        else if(s[i]=='L') nx--;
        else nx++;
    }
    return (abs(nx-x)+abs(ny-y))<=m;
}
int main()
{
    ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    x=x2-x1,y=y2-y1;
    cin>>n;
    cin>>s;
    ll lo=0,hi=1e18;
    while(lo<hi)
    {
        ll m=(lo+hi)/2;
        if(check(m)) hi=m;
        else lo=m+1;
    }
    if(hi==1e18) cout<<-1<<endl;
    else cout<<lo<<endl;
}