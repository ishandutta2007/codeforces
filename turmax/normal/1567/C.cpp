#include <bits/stdc++.h>

using namespace std;
#define int long long
map <pair<int,int>,int> u;
int go(int n,int m)
{
    if(m>n) return 0;
    if(n==0)
    {
        return 1;
    }
    if(u.count({n,m})) return u[{n,m}];
    int ans=0;
    int r=m%10;
    for(int i=0;i<=9;++i) for(int j=0;j<=9;++j)
    {
        if(((i+j+r)%10)!=(n%10))
        {
            continue;
        }
        else if((i+j+r)<10)
        {
            ans+=go(n/10,m/10);
        }
        else
        {
            ans+=go(n/10,m/10+10);
        }
    }
    u[{n,m}]=ans;
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
        cout<<go(n,0)-2<<endl;
    }
    return 0;
}