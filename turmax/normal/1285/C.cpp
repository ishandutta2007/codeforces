#include <bits/stdc++.h>

using namespace std;
#define int long long
int gcd(int x,int y)
{
    if(x==0)
    {
        return y;
    }
    if(y==0)
    {
        return x;
    }
    if(x>=y)
    {
        return gcd(x%y,y);
    }
    return gcd(x,y%x);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x;
    cin>>x;
    int ans=1;
    for(int i=1;i*i<=x;++i)
    {
        if(x%i==0 && gcd(i,x/i)==1)
        {
            ans=i;
        }
    }
    cout<<ans<<" "<<x/ans;
    return 0;
}