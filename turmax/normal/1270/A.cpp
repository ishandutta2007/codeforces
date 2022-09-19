#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n,k1,k2;
    cin>>n>>k1>>k2;
    int x;
    int ma1=(-1);
    int ma2=(-1);
    for(int i=0;i<k1;++i)
    {
        cin>>x;
        ma1=max(ma1,x);
    }
    for(int i=0;i<k2;++i)
    {
        cin>>x;
        ma2=max(ma2,x);
    }
    if(ma1>ma2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}