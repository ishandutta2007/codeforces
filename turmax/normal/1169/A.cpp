#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
    for(int i=0;i<n;++i)
    {
        if(a==b)
        {
            cout<<"YES";
            return 0;
        }
        if(a==x)
        {
            cout<<"NO";
            return 0;
        }
        if(b==y)
        {
            cout<<"NO";
            return 0;
        }
        ++a;
        --b;
        a+=n;
        b+=n;
        a%=n;
        b%=n;
        if(a==0)
        {
            a=n;
        }
        if(b==0)
        {
            b=n;
        }
    }
    return 0;
}