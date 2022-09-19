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
    int n,x,a,b;
    cin>>n>>x>>a>>b;
    cout<<min(n-1,abs(a-b)+x)<<endl;
    }
    return 0;
}