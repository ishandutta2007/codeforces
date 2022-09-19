#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector<int> v[maxn];int arr[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) v[i].clear();
        for(int i=0;i<maxn;++i) arr[i]=i;
        for(int i=0;i<n;++i)
        {
            int x=a[i];
            for(int j=1;j<=k;++j)
            {
                if(j==1 || (x/j)!=(x/(j-1))) v[i].push_back(x/j);
            }
            reverse(v[i].begin(),v[i].end());v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
        }
        for(int i=0;i<n;++i)
        {
             arr[v[i].back()+1]=1e9;
             for(int j=0;j<((int) v[i].size());++j)
             {
                 arr[v[i][j]+1]=max(arr[v[i][j]+1],v[i][j+1]);
             }
             arr[1]=max(arr[1],v[i][0]);
        }
        for(int i=1;i<maxn;++i) arr[i]=max(arr[i],arr[i-1]);
        int ans=1e9;
        for(int i=1;i<maxn;++i)
        {
            ans=min(ans,arr[i]-i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}