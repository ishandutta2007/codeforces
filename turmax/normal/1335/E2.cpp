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
    vector <int> b[201];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        b[a[i]].push_back(i);
    }
    int ans=0;
    for(int i=0;i<=200;++i)
    {
        ans=max(ans,(int) b[i].size());
        for(int j=1;j<=(b[i].size()/2);++j)
        {
            //cout<<i<<" "<<j<<endl;
            int l=b[i][j-1]+1;
            int r=b[i][b[i].size()-j]-1;
            if(r<l)
            {
                ans=max(ans,2*j);
                continue;
            }
            int sum=(2*j);
            int ans1=0;
            for(int k=0;k<=200;++k)
            {
                ans1=max(ans1,sum+(upper_bound(b[k].begin(),b[k].end(),r)-lower_bound(b[k].begin(),b[k].end(),l)));
            }
            ans=max(ans,ans1);
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}