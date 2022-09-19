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
    int n,m,k;
    cin>>n>>m>>k;
    int x=(n/k);
    if(x>=m)
    {
        cout<<m<<endl;
        continue;
    }
    int u=m-x;
    int z=((u+k-2)/(k-1));
    cout<<x-z<<endl;
    }
    return 0;
}