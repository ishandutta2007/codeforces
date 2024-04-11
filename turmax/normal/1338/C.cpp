#include <bits/stdc++.h>

using namespace std;
#define int long long
int f1(int y)
{
    if(y%4==0)
    {
        return y;
    }
    if(y%4==1)
    {
        return y+1;
    }
    if(y%4==2)
    {
        return y+1;
    }
    if(y%4==3)
    {
        return y-2;
    }
}
int f2(int y)
{
    if(y%4==0)
    {
        return y;
    }
    if(y%4==1)
    {
        return y+2;
    }
    if(y%4==2)
    {
        return y-1;
    }
    if(y%4==3)
    {
        return y-1;
    }
}
int f11(int y)
{
    int ans=0;
    int u=1;
    while(y!=0)
    {
        ans+=f1(y%4)*u;
        y/=4;
        u*=4;
    }
    return ans;
}
int f12(int y)
{
    int ans=0;
    int u=1;
    while(y!=0)
    {
        ans+=f2(y%4)*u;
        y/=4;
        u*=4;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int u=1;
    int x=(n%3);
    int y=((n-1)/3);
    while((u-1)<n)
    {
        u*=4;
    }
    u/=4;
    y-=((u-1)/3);
    if(x==1)
    {
        cout<<u+y<<endl;
        continue;
    }
    if(x==2)
    {
        cout<<2*u+f11(y)<<endl;
    }
    if(x==0)
    {
        cout<<3*u+f12(y)<<endl;
    }
    }
    return 0;
}