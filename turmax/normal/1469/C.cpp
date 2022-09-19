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
        k--;
        int a[n];
        int b[n];
        int c[n];
        for(int i=0;i<n;++i) {cin>>a[i];b[i]=a[i]-(i*k);c[i]=a[i]+(i*k);}
        c[n-1]=a[n-1]+((n-2)*k);
        b[0]=a[0]-k;
        bool ans=true;
        int mi=1e18;
        for(int i=0;i<n;++i)
        {
            if(b[i]>(mi+k))
            {
                ans=false;
            }
            mi=min(mi,b[i]);
        }
        int ma=(-1e18);
        for(int i=0;i<n;++i)
        {
            if(c[i]<(ma-k))
            {
                ans=false;
            }
            ma=max(ma,c[i]);
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}