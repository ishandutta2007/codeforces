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
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int curr=n;
        for(int i=(n-1);i>=0;i--) if(a[i]==(i+1)) curr--; else break;
        double ans=1;
        for(int i=0;i<m;++i) {int c;double p;cin>>c>>p;if(c>=curr) ans*=(1.0-p);}
        if(curr==0) ans=0;
        cout<<setprecision(15)<<(1-ans)<<endl;
    }
    return 0;
}