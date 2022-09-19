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
        int n;
        cin>>n;
        if(n<6) cout<<15<<'\n';
        else cout<<((n+1)/2)*5<<'\n';
    }
    return 0;
}