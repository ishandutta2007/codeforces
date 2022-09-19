#include <bits/stdc++.h>

using namespace std;
#define int long long
int po[32];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u=1;
    for(int i=0;i<32;++i)
    {
        po[i]=u;
        u*=2;
    }
    int t;
    cin>>t;
    while(t--)
    {
    int d,m;
    cin>>d>>m;
    int r=1;
    int z=1;
    for(int i=0;i<32;++i)
    {
        if(po[i]<=d && po[i+1]>d)
        {
            r=d-po[i]+2;
            for(int j=0;j<i;++j)
            {
                z*=(po[j]+1);
                z%=m;
            }
        }
    }
    cout<<((z*r-1)%m+m)%m<<endl;
    }
    return 0;
}