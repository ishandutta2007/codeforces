#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n>m)
    {
        swap(n,m);
    }
    if(n==1)
    {
        int z1=((m+2)/3);
        int z2=((m+1)/3);
        int z3=((m)/3);
        cout<<((z1/2+z2/2+z3/2)*2);
        return 0;
    }
    if(n==2)
    {
        if(m==3)
        {
            cout<<2*2;
            return 0;
        }
        if(m==7)
        {
            cout<<2*6;
            return 0;
        }
        if(m>=4)
        {
            cout<<2*m;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(n%2==1 && m%2==1)
    {
        cout<<(n*m-1);
        return 0;
    }
    cout<<(n*m);
    return 0;
}