#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n%4==0)
    {
        cout<<1<<" A";
        return 0;
    }
    if(n%4==2)
    {
        cout<<1<<" B";
        return 0;
    }
    if(n%4==3)
    {
        cout<<2<<" A";
        return 0;
    }
    if(n%4==1)
    {
        cout<<0<<" A";
        return 0;
    }
    return 0;
}