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
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"FastestFinger"<<endl;
        continue;
    }
    if(n%2==1 || n==2)
    {
        cout<<"Ashishgup"<<endl;
        continue;
    }
    int o=1;
    while(n%2==0)
    {
        o*=2;
        n/=2;
    }
    if(n==1)
    {
        cout<<"FastestFinger"<<endl;
        continue;
    }
    if(o!=2)
    {
        cout<<"Ashishgup"<<endl;
        continue;
    }
    bool h=false;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            cout<<"Ashishgup"<<endl;
            h=true;
            break;
        }
    }
    if(!h)
    {
        cout<<"FastestFinger"<<endl;
        continue;
    }
    }
    return 0;
}