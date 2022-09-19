#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int n1=n;int ans[n]={0};
        while(n>=1)
        {
        if(n==1)
        {
            ans[0]=0;break;
        }
        int i=1;while((i+1)*(i+1)<=2*n-2) ++i;
        int x=i*i;
        for(int i=x-n+1;i<n;++i)
        {
            int u=x-i;
            ans[i]=u;
        }
        n=x-n+1;
        }
        for(int i=0;i<n1;++i) cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}