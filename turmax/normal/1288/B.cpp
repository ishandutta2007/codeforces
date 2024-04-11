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
    int a,b;
    cin>>a>>b;
    ++b;
    int s=0;
    while(b!=0)
    {
        b/=10;
        ++s;
    }
    s--;
    cout<<a*s<<endl;
    }
    return 0;
}