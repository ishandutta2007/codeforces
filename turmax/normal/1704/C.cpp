#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;int a[m+1];for(int i=0;i<m;++i) cin>>a[i]; sort(a,a+m); a[m]=a[0]+n;
        int b[m];for(int i=0;i<m;++i) b[i]=a[i+1]-a[i]-1; sort(b,b+m);reverse(b,b+m);
        int ans=0;for(int i=0;i<m;++i) {int x=b[i]-4*i;if(x==1) ++ans; ans+=max(0LL,x-1);}
        cout<<n-ans<<'\n';
    }
    return 0;
}