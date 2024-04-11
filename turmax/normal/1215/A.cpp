#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a1,a2,k1,k2;
    int n;
    cin>>a1>>a2>>k1>>k2>>n;
    int x;
    x=(n-(k1-1)*a1-(k2-1)*a2);
    if(x<0)
    {
        cout<<0<<" ";
    }
    else
    {
        cout<<x<<" ";
    }
    int y;
    if(k1>=k2)
    {
        swap(k1,k2);
        swap(a1,a2);
    }
    int z=k1*a1;
    if(z>=n)
    {
        cout<<n/k1;
        return 0;
    }
    else
    {
        cout<<a1+(n-z)/k2;
        return 0;
    }
    return 0;
}