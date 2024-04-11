#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;const int sq=350;
int arr[maxn];
vector<int> h;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    h.reserve(maxn);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<maxn;++i) arr[i]=i;
        for(int i=0;i<n;++i)
        {
            h.clear();
            int x=a[i];
            for(int j=1;j<=min(k,sq);++j)
            {
                h.push_back(x/j);
            }
            for(int j=1;j<=sq;++j)
            {
                if((x/(j+1)+1)<=k && x/(x/(j+1)+1)==j)
                {
                    h.push_back(j);
                }
            }
            sort(h.begin(),h.end());h.erase(unique(h.begin(),h.end()),h.end());
            arr[h.back()+1]=1e9;
            for(int j=0;j<((int) h.size());++j)
             {
                 arr[h[j]+1]=max(arr[h[j]+1],h[j+1]);
             }
             arr[1]=max(arr[1],h[0]);
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