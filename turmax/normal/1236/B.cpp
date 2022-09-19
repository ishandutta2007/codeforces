#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=(1e9+7);
int po(int x,int y)
{
    if(y==0)
    {
        return 1;
    }
    if(y==1)
    {
        return x;
    }
    else if(y%2==0)
    {
        int u=po(x,y/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(x,y-1);
        return (u*x)%p;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a=po(2,m)-1;
    a+=p;
    a%=p;
    int ans=po(a,n);
    cout<<ans;
    return 0;
}