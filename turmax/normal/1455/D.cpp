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
        int n,x;
        cin>>n>>x;
        int a[n];
        int ans=0;
        bool h=true;
        bool is[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        is[n-1]=true;
        for(int i=(n-2);i>=0;i--)
        {
            if(a[i+1]<a[i])
            {
                is[i]=false;
            }
            else
            {
                is[i]=is[i+1];
            }
        }
        for(int i=0;i<n;++i) {if(i!=0 && a[i]<a[i-1]) {if(h) cout<<(-1)<<endl; h=false;break;}if(is[i]) break;if(a[i]>x) {swap(a[i],x);++ans;}}
        if(h)
        cout<<ans<<endl;
    }
    return 0;
}