#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int x,y,z;
    cin>>x>>y>>z;
    int u=max(max(x,y),z);
    if((x+y)!=(2*u) && (y+z)!=(2*u) && (z+x)!=(2*u))
    {
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;
    if(x==u && y==u)
    cout<<u<<" "<<max(0LL,max(y+z-u,z+x-u))<<" "<<1<<endl;
    else if(x==u && z==u)
    {
        cout<<1<<" "<<u<<" "<<max(x+y-u,max(y+z-u,0LL))<<endl;
    }
    else
    {
         cout<<1<<" "<<max(x+y-u,max(0LL,z+x-u))<<" "<<u<<endl;
    }
    }
    return 0;
}