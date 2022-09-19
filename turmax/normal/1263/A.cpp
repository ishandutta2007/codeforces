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
    cout<<min(min((a+b+c)/2,b+c),min(a+c,a+b))<<endl;
    }
    return 0;
}