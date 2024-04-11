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
    int c8=(n+3)/4;
    for(int i=0;i<(n-c8);++i)
    {
        cout<<9<<"";
    }
    for(int i=0;i<c8;++i) cout<<8<<"";
    cout<<endl;
    }
    return 0;
}