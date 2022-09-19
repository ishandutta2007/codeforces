#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int low=0;int up=1e6;
        while(up-low>1)
        {
            int mid=(low+up)/2;
            int a=(mid/3);int b=(mid+1)/3;int c=(mid+2)/3;
            if(a*b+b*c+c*a>=(n+1)/2) up=mid;
            else low=mid;
        }
        cout<<up<<'\n';
    }
    return 0;
}