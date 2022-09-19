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
    int sum=0;
    int z=abs(a-b);
    for(int i=0;i<50000;++i)
    {
        sum+=i;
        if(sum>=z && ((sum-z)%2)==0)
        {
            cout<<i<<endl;
            break;
        }
    }
    }
    return 0;
}