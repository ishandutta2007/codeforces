#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=100000;
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
        cout<<(-1)<<endl;
        continue;
    }
    if(n%3==1)
    {
        for(int i=0;i<(n-2);++i)
        {
            cout<<'8';
        }
        for(int i=0;i<2;++i)
        {
            cout<<'9';
        }
        cout<<endl;
        continue;
    }
    if(n%3==2)
    {
        for(int i=0;i<(n-1);++i)
        {
            cout<<'8';
        }
        for(int i=0;i<1;++i)
        {
            cout<<'9';
        }
        cout<<endl;
        continue;
    }
    if(n%3==0)
    {
        for(int i=0;i<(n-1);++i)
        {
            cout<<'8';
        }
        for(int i=0;i<1;++i)
        {
            cout<<'9';
        }
        cout<<endl;
    }
    }
    return 0;
}