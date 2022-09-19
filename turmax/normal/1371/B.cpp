#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,r;
    cin>>n>>r;
    cout<<min(r*(r+1)/2,(n-1)*n/2+1)<<endl;
    }
    return 0;
}