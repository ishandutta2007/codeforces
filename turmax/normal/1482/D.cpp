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
        int n,m;
        cin>>n>>m;
        swap(n,m);
        int x;
        cin>>x;
        int a=(x-1)/m;
        int b=(x-1)%m;
        cout<<(1+b*n+a)<<endl;
    }
    return 0;
}