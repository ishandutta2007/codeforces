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
        int n,k;
        cin>>n>>k;
        vector <int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a.begin(),a.end());
        int ans=0;
        vector <int> b=a;
        b[n-1]+=b[0];
        b[0]=0;
        for(int i=(n-2);i>(n-k-1);--i)
        {
            b[n-1]+=b[i];
        }
        ans=b[n-1];
        vector <int> c=a;
        for(int i=(n-2);i>=(n-k-1);--i)
        {
            c[n-1]+=c[i];
            c[i]=0;
        }
        ans=max(ans,c[n-1]);
        cout<<ans<<endl;
    }
    return 0;
}