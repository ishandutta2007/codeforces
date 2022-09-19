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
        int a[n];
        int x,y;
        for(int i=0;i<n;++i) {cin>>a[i];if(a[i]==1) x=i;else if(a[i]==n) y=i;}
        cout<<min(min(max(x+1,y+1),max(n-x,n-y)),n-abs(y-x)+1)<<'\n';
    }
    return 0;
}