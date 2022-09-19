#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=100000;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int b[n];
    b[0]=a[0];
    int ma=b[0];
    for(int i=1;i<n;++i)
    {
        b[i]=ma+a[i];
        ma=max(ma,b[i]);
    }
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}