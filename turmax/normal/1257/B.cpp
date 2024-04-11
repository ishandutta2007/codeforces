#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cycle=0;cycle<t;++cycle)
    {
    int a,b;
    cin>>a>>b;
    if(a==1 && b!=1)
    {
        cout<<"NO"<<endl;
        continue;
    }
    if(a<=3 && b>3)
    {
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;
    }
    return 0;
}