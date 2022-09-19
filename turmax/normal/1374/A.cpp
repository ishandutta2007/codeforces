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
    int x,y,n;
    cin>>x>>y>>n;
    int u=(n-y);
    cout<<(u/x)*x+y<<endl;
    }
    return 0;
}