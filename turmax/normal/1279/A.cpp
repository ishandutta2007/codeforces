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
    int a,b,c;
    cin>>a>>b>>c;
    int z=max(c,max(a,b));
    if((2*z-1)>(a+b+c))
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
    cout<<endl;
    }
    return 0;
}