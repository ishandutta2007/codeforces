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
    int a,b,n;
    cin>>a>>b>>n;
    int z=0;
    while(true)
    {
        ++z;
        if(a>=b)
        {
            b+=a;
        }
        else
        {
            a+=b;
        }
        if(max(a,b)>n)
        {
            cout<<z<<endl;
            break;
        }
    }
    }
    return 0;
}