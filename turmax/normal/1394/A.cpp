#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,d,m;
    cin>>n>>d>>m;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    vector <int> v1;
    vector <int> v2;
    for(int i=0;i<n;++i)
    {
        if(a[i]<=m)
        {
            v1.push_back(a[i]);
        }
        else
        {
            v2.push_back(a[i]);
        }
    }
    reverse(v1.begin(),v1.end());reverse(v2.begin(),v2.end());
    int sum=0;
    int u=((n+d)/(d+1));
    int o=n;
    int sum2=0;
    for(int i=0;i<min(u,(int) v2.size());++i)
    {
        sum2+=v2[i];
    }
    int ans=sum2;
    for(int i=0;i<v1.size();++i)
    {
        sum+=v1[i];
        o--;
        if(o%(d+1)==0)
        {
            if((u-1)<v2.size())
            sum2-=v2[u-1];
            u--;
        }
        ans=max(ans,sum+sum2);
    }
    cout<<ans;
    return 0;
}