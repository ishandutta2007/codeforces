#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cycle=0;cycle<t;++cycle)
    {
    int a,b,c;
    cin>>a>>b>>c;
    int x,y,z;
    int ma=0;
    for(int i=0;i<100;++i)
    {
        for(int j=0;j<100;++j)
        {
            x=a;
            y=b;
            z=c;
            x-=i;
            z-=(2*j);
            y-=(2*i+j);
            if(x>=0 && y>=0 && z>=0)
            {
                ma=max(ma,3*(i+j));
            }
        }
    }
    cout<<ma<<endl;
    }
    return 0;
}